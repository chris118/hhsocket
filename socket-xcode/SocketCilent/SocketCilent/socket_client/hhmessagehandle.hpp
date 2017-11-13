//
//  hhmessagehandle.cpp
//  SocketCilent
//
//  Created by xiaopeng on 2017/6/9.
//  Copyright © 2017年 PT. All rights reserved.
//

#include <string>
#include <iostream>
#include <assert.h>
#include <stdint.h>

#include "../ProtoBuf/person.pb.h"

using namespace std;

class ProtoMsgHandle
{
public:
    /*  注册消息处理函数 */
    void initHandles()
    {
        registerHandle(&ProtoMsgHandle::handleProtoPerson);
    }
    
    /*  处理网络消息
     *  data 为一个完整的数据包
     */
    void handle(const char* data, int size)
    {
        bool ret = false;
        
        const char * current=data;
        
        
        //在网络上传输的一个数据包总长度
        int packetLength=0;
        
        //从第一个位置上获取到数据包总长度
        memcpy(&packetLength, data, sizeof(int32_t));
        
        //指针后移
        current+=sizeof(int32_t);
        
        //Message名字的长度
        int protoNameLength=0;
        
        //从第二个位置上获取Message的名字的长度
        memcpy(&protoNameLength, current, sizeof(int32_t));
        
        //指针后移
        current+=sizeof(int32_t);
        
        //从第三个位置上获取Message的名字
        string name(current,protoNameLength);
        
        //指针后移
        current+=protoNameLength;
        
        //取得Message的字节数
        int messageSize=packetLength-(sizeof(int32_t)+sizeof(int32_t)+protoNameLength);
        
        do{
            
            msg_handle callback = m_callbacks[name];
            
            assert(callback != NULL);
            
            if(callback == NULL)
            {
                std::cout<<"proto "<<name<<" had not register handler"<<std::endl;
                break;
            }
            const ::google::protobuf::Descriptor* descriptor = m_descriptors[name];
            assert(descriptor != NULL);
            if(descriptor == NULL)
            {
                std::cout<<"proto "<<name<<" had no descriptor"<<std::endl;
                break;
            }
            const google::protobuf::Message* prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
            assert(prototype != NULL);
            if(prototype == NULL)
            {
                std::cout<<"proto "<<name<<" had no prototype"<<std::endl;
                break;
            }
            google::protobuf::Message* msg = prototype->New();
            ret = msg->ParseFromArray(current,messageSize);
            if(ret)
            {
                (this->*callback)(msg);
            }
            else
            {
                std::cout<<"proto "<<name<<" parse fail"<<std::endl;
            }
            
        }while(0);
    }
private:
    void handleProtoPerson(person* person)
    {
        cout << "person->age()="<<person->age() << endl;
        cout << "person->userid()="<<person->userid() << endl;
        cout << "person->name()="<<person->name() << endl;
    }
    
private:
    
    typedef void (ProtoMsgHandle::*msg_handle)(::google::protobuf::Message*);
    
    map<string, msg_handle>                                 m_callbacks;
    
    map<string, const ::google::protobuf::Descriptor*>      m_descriptors;
    
    template<typename MSGTYPE>
    void registerHandle(void (ProtoMsgHandle::*callback)(MSGTYPE*))
    {
        const ::google::protobuf::Descriptor*des =MSGTYPE::descriptor();
        assert(des != NULL);
        if(des != NULL)
        {
            m_callbacks[des->full_name()] = (msg_handle)callback;
            m_descriptors[des->full_name()] = des;
        }
    }
};
