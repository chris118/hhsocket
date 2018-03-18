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
        m_stop = false;
    }
    
    void setSocket(Socket *socket, string ip, int port){
        m_socket = socket;
        m_ip = ip;
        m_port = port;
    }
    
    HHResult reconnect(){
        if(m_socket->is_valid()){
            m_socket->close();
        }

        if ( ! m_socket->create() )
        {
            return NET_ERROR;
        }
        
        if ( ! m_socket->connect ( m_ip, m_port ) )
        {
            return NET_ERROR;
        }
        
        return OK;
    }
    
    void stop(){
        cout << "stop()" << endl;
        m_stop = true;
    }
    
    ~HHAlarmTask(){
        
    }
    
    virtual int run(){
        // m_callback = (HHlientCallback * )arg_;
        cout << "m_stop: " << m_stop << endl;
        cout << "m_socket: " << m_socket << endl;
        while (!m_stop && m_socket) {
            try {
                //收消息头
                HHHeader header;
                m_socket->recv(&header, sizeof(header));
                
                cout << "------------"<< "flag:" << header.flag<< " seq: " << header.seq<<  " length: "<< header.msg_length<< "------------"<< endl;
                if(header.flag != 0xffff){
                    HHLOG("bad package! try to reconnect");
                    reconnect();
                    continue;
                }
                
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
                            m_socket->recv(buf, TRUNK_SIZE);
                            memcpy(protoMsgBuf + read_length, buf, TRUNK_SIZE);
                            read_length += TRUNK_SIZE;
                            left_length -= TRUNK_SIZE;
                        }else{
                            char buf[left_length];
                            m_socket->recv(buf, left_length);
                            memcpy(protoMsgBuf + read_length, buf, left_length);
                            left_length = 0;
                        }
                    }
                }else{
                    char buf[messageSize];
                    m_socket->recv(buf, messageSize);
                    memcpy(protoMsgBuf, buf, messageSize);
                }
                
                //反序列化
                const ::google::protobuf::Descriptor*descriptor =AlarmInfo::descriptor();
                const google::protobuf::Message* prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
                google::protobuf::Message* msgProtobuf = prototype->New();
                bool ret = msgProtobuf->ParseFromArray(protoMsgBuf, messageSize);
                if (ret == false)
                {
                    HHLOG("Deserialize error");
                    if(reconnect() != OK){
                    }
                }
                
                AlarmInfo *alarm_info = static_cast<class AlarmInfo*>(msgProtobuf) ;
                
                //    cout << "id = " << alarm_info->id() << endl;
                //    cout << "obj_type = " <<alarm_info->obj_type() << endl;
                //    cout << "timestamp = " << alarm_info->timestamp() << endl;
                //    cout << "x = " << alarm_info->x() << endl;
                //    cout << "y = " << alarm_info->y() << endl;
                //    cout << "w = " << alarm_info->w() << endl;
                //    cout << "h = " << alarm_info->h() << endl;
                //    cout << "start_timestamp = " << alarm_info->start_timestamp() << endl;
                //    cout << "end_timestamp = " << alarm_info->end_timestamp() << endl;
                //    cout << "credibility = " << alarm_info->credibility() << endl;
                
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
                    alarm.image_id = alarm_info->image_id();
                    alarm.image_width = alarm_info->image_width();
                    alarm.image_height = alarm_info->image_height();
                    
                    // alarm image
                    string alarm_pic = alarm_info->alarm_pic();
                    alarm.alarm_pic = (char*)alarm_pic.c_str();
                    alarm.alarm_pic_size = alarm_pic.length();
                    
                    //source image
                    string src_image = alarm_info->src_image();
                    alarm.src_image = (char*)src_image.c_str();
                    alarm.src_image_size = src_image.length();
                    
                    m_callback->onAlarm(alarm);
                }
                
                if(msgProtobuf){
                    msgProtobuf->Clear();
                    delete msgProtobuf;
                }
                
            } catch (...) {
                
            }
            sleep(2);
        }
        
        cout << "task is over" << endl;
        
        return 1;
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
    Socket* m_socket;
    string m_ip;
    int m_port;
    int m_packet_index = 0;
    bool m_stop;
    
};
