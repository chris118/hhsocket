//
//  hhmessagesender.cpp
//  SocketServer
//
//  Created by xiaopeng on 2017/6/8.
//  Copyright © 2017年 PT. All rights reserved.
//

#include <string>
#include <iostream>
#include <assert.h>
#include <stdint.h>

#include "person.pb.h"

using namespace std;

class ProtoMessageSender
{
public:
    template<typename MSGTYPE>
    static int sendMessageToBuffer(Client client, MSGTYPE& msg, char* buffer, int maxLength){
        
        char * current=buffer;
         int messageSize=msg.ByteSize();
        
        HHHeader header;
        header.flag = 0xffff;
        header.seq = client.id;
        header.type = 1;
        header.msg_length = messageSize;//Message的字节数
        header.reserved = 0;
        
        //头信息
        memcpy(current, &header, sizeof(header));
        
        //将Message放在header后
        msg.SerializeToArray(current,messageSize);

        return (int)messageSize;
    }
};
