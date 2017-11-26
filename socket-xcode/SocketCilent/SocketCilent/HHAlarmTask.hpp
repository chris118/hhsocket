//
//  HHAlarmTask.hpp
//  CallBackDemo
//
//  Created by Chris on 2017/11/7.
//  Copyright © 2017年 putao. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <errno.h>
#include <vector>
#include <pthread.h>
#include <thread>
#include <signal.h>

#include <sys/syscall.h>
#define gettid() syscall(__NR_gettid)

#include "core/ThreadPool.h"
#include "core/HHLog.hpp"
#include "core/HHLog.hpp"
#include "core/Util.hpp"
#include "socket_base/Socket.h"
#include "socket_base/SocketException.h"
#include "socket_client/ClientSocket.h"
#include "socket_client/hhpacket.hpp"
#include "socket_client/hhmessagehandle.hpp"
#include "alarm.pb.h"

using namespace std;
using namespace hhclient;

class HHAlarmTask: public Task
{
public:
    HHAlarmTask(HHlientCallback * callback){
        m_callback = callback;
    }

    virtual int run(){
        m_callback = (HHlientCallback * )arg_;
        while (true) {
            try {
                //收消息头
                HHHeader header;
                m_socket.recv(&header, sizeof(header));
                
                //收消息体
                int messageSize = header.msg_length;
                char protoMsgBuf[messageSize];
                
                //分小块收取
                if(messageSize > MAXRECV){
                    int left_length = messageSize;
                    int read_length = 0;
                    const int TRUNK_SIZE = 100;

                    while (left_length > 0) {
                        if(left_length > TRUNK_SIZE){
                            char buf[TRUNK_SIZE];
                            m_socket.recv(buf, TRUNK_SIZE);
                            memcpy(protoMsgBuf + read_length, buf, TRUNK_SIZE);
                            read_length += TRUNK_SIZE;
                            left_length -= TRUNK_SIZE;
                        }else{
                            char buf[left_length];
                            m_socket.recv(buf, left_length);
                            memcpy(protoMsgBuf + read_length, buf, left_length);
                            left_length = 0;
                        }
                    }
                }else{
                    char buf[messageSize];
                    m_socket.recv(buf, messageSize);
                    memcpy(protoMsgBuf, buf, messageSize);
                }
                
                //反序列化
                const ::google::protobuf::Descriptor*descriptor =AlarmInfo::descriptor();
                const google::protobuf::Message* prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
                google::protobuf::Message* msgProtobuf = prototype->New();
                bool ret = msgProtobuf->ParseFromArray(protoMsgBuf, (int)sizeof(protoMsgBuf));
                if (ret == false)
                {
                    cout << "Deserialize error !" << endl;
                    sleep(2);
                    continue;
                }
                
                AlarmInfo *alarm_info = static_cast<class AlarmInfo*>(msgProtobuf) ;
                
//                cout << "id = " << alarm_info->id() << endl;
//                cout << "obj_type = " <<alarm_info->obj_type() << endl;
//                cout << "timestamp = " << alarm_info->timestamp() << endl;
//                cout << "x = " << alarm_info->x() << endl;
//                cout << "y = " << alarm_info->y() << endl;
//                cout << "w = " << alarm_info->w() << endl;
//                cout << "h = " << alarm_info->h() << endl;
//                cout << "start_timestamp = " << alarm_info->start_timestamp() << endl;
//                cout << "end_timestamp = " << alarm_info->end_timestamp() << endl;
//                cout << "credibility = " << alarm_info->credibility() << endl;
//
                if(m_callback){
                    HHAlarm alarm;
                    alarm.id = alarm_info->id();
                    alarm.car_type = (HHCarType)alarm_info->obj_type();
                    alarm.timestamp = alarm_info->timestamp();
                    alarm.coordinate[0] = alarm_info->x();
                    alarm.coordinate[1] = alarm_info->y();
                    alarm.coordinate[2] = alarm_info->w();
                    alarm.coordinate[3] = alarm_info->h();
                    alarm.start_timestamp = alarm_info->start_timestamp();
                    alarm.end_timestamp = alarm_info->end_timestamp();
                    alarm.credibility = alarm_info->credibility();
                    
                    string src = alarm_info->src_image();
                    cout << src << endl;
                    alarm.src_image = (char*)src.c_str();
                    alarm.src_image_size = src.length();

                    m_callback->onAlarm(alarm);
                }

            } catch (...) {
                
            }
            sleep(2);
        }
        
        return 1;
    }
    
    void setSocket(Socket &socket){
        m_socket = socket;
    }
    
    ~HHAlarmTask(){
   
    }
    
private:
    bool send_packet(Socket& socket, int packet_index,
                     google::protobuf::Message &msg){
        
        HHHeader header;
        header.flag = 0xffff;
        header.seq = packet_index;
        header.msg_length = msg.ByteSize();//Message的字节数
        header.type = 1;
        header.reserved = 0;
        
        int headerSize = sizeof(HHHeader);
        int msgSize= msg.ByteSize();
        int packetSize = headerSize + msgSize;
        
        char msgBuff[msgSize];
        msg.SerializeToArray(msgBuff,msgSize);
        
        // packet
        char packetBuff[packetSize];
        //头信息
        memcpy(packetBuff, &header, headerSize);
        //msg 信息
        memcpy(packetBuff + headerSize, msgBuff, msgSize);
        
        bool ret = socket.send(packetBuff, packetSize);
        if(!ret){
            cout << "socket send error !" << endl;
        }
        
        return ret;
    }
    
private:
    HHlientCallback * m_callback;
    Socket m_socket;

    int m_packet_index = 0;
    
};



//        while(1){
//            if (m_callback) {
//
//                //模拟报警消息
//                HHAlarm alarm;
//                alarm.car_type = TRUCK_CRANE;
//                time_t t;
//                alarm.timestamp =  time(&t);
//                alarm.coordinate[0] = 30;
//                alarm.coordinate[1] = 30;
//                alarm.coordinate[2] = 100;
//                alarm.coordinate[3] = 100;
//                alarm.start_timestamp = time(&t);
//                alarm.end_timestamp = time(&t);
//                alarm.credibility = 0.89;
//
//
//                //模拟报警图片
//                filebuf *pbuf;
//                long size;
//                char * buffer;
//                ifstream filestr("./hhclient/test.jpg", ios::binary);
//                pbuf=filestr.rdbuf();
//                size=pbuf->pubseekoff (0,ios::end,ios::in);
//                pbuf->pubseekpos (0,ios::in);
//                buffer=new char[size];
//                pbuf->sgetn (buffer,size);
//                filestr.close();
//
//                alarm.alarm_pic_size = size;
//                alarm.alarm_pic = buffer;
//                alarm.alarm_vid_size = size;
//                alarm.alarm_vid = buffer;
//                alarm.src_image_size = size;
//                alarm.src_image = buffer;
//
//                m_callback->onAlarm(alarm);
//
//                delete buffer;
//                // delete alarm.alarm_pic;
//                // delete alarm.alarm_vid;
//                // delete alarm.src_image;
//            }
//            sleep(10);
//        }






//    try
//    {
//        Socket socket;
//        HHLOG("main starting.... ");
//
//        if ( ! socket.create() )
//        {
//            throw SocketException ( "Could not create client socket." );
//        }
//
//        if ( ! socket.connect ( "127.0.0.1", 30666 ) )
////        if ( ! socket.connect ( "49.91.240.3", 9999 ) )
//        {
//            throw SocketException ( "Could not bind to port." );
//        }
//
////        ProtoMsgHandle msghandle;
////        msghandle.initHandles();
//
//        while (true) {
//
//            try {
//                HHLogin loginMsg;
//                loginMsg.set_port(8000);
//                loginMsg.set_version(5);
//                loginMsg.set_clienttype(HHLogin_eClientType::HHLogin_eClientType_eTx2);
//
//                bool ret = send_packet(socket, packet_index, loginMsg);
//                packet_index++;
//                if(!ret){
//                    cout << "socket send error !" << endl;
//                }else{
//                    cout << "send packet success!" << endl;
//                }
//
//                //收消息头
//                HHHeader header;
//                socket.recv(&header, sizeof(header));
//
//                //收消息体
//                int messageSize = header.msg_length;
//                char protoMsgArray[messageSize];
//                socket.recv(&protoMsgArray, (int)sizeof(protoMsgArray));
//
//                //反序列化
//                const ::google::protobuf::Descriptor*descriptor =HHLogin::descriptor();
//                const google::protobuf::Message* prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
//                google::protobuf::Message* msgProtobuf = prototype->New();
//                ret = msgProtobuf->ParseFromArray(protoMsgArray, (int)sizeof(protoMsgArray));
//                if (ret == false)
//                {
//                    cout << "Deserialize error !" << endl;
//                    continue;
//                }
//
//                HHLogin *login_msg = static_cast<class HHLogin*>(msgProtobuf) ;
//
//                cout << "login_msg->port() ="<<login_msg->port() << endl;
//                cout << "login_msg->version()="<<login_msg->version() << endl;
//                cout << "login_msg->clienttype()="<<login_msg->clienttype() << endl;
//
//            } catch (...) {
//
//            }
//            sleep(1);
//        }
//    }
//    catch ( SocketException& e )
//    {
//        std::cout << "Exception was caught:" << e.description() << "\n";
//    }



//bool send_packet(Socket& socket, int packet_index,
//                        google::protobuf::Message &msg){
//
//    HHHeader header;
//    header.flag = 0xffff;
//    header.seq = packet_index;
//    header.msg_length = msg.ByteSize();//Message的字节数
//    header.type = 1;
//    header.reserved = 0;
//
//    int headerSize = sizeof(HHHeader);
//    int msgSize= msg.ByteSize();
//    int packetSize = headerSize + msgSize;
//
//    char msgBuff[msgSize];
//    msg.SerializeToArray(msgBuff,msgSize);
//
//    // packet
//    char packetBuff[packetSize];
//    //头信息
//    memcpy(packetBuff, &header, headerSize);
//    //msg 信息
//    memcpy(packetBuff + headerSize, msgBuff, msgSize);
//
//    bool ret = socket.send(packetBuff, packetSize);
//    if(!ret){
//        cout << "socket send error !" << endl;
//    }
//
//    return ret;
//}

//int packet_index = 0;


