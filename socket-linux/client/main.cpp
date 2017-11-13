//
//  main.cpp
//  hhsocket_client
//
//  Created by xiaopeng on 16/9/5.
//  Copyright © 2016年 hh. All rights reserved.
//
#include "ClientSocket.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include "utility/HHLog.hpp"
#include "hhpacket.hpp"
#include "utility/Utility.h"

#include "socket_base/Socket.h"
#include "socket_base/SocketException.h"
#include "hhmessagehandle.hpp"
#include "person.pb.h"

using namespace std;

int main(int argc, const char * argv[])
{
    try
    {
        // test purpose:"127.0.0.1", "30000"
        Socket socket;
        LOG("main starting.... ");
        
        if ( ! socket.create() )
        {
            throw SocketException ( "Could not create client socket." );
        }
        
        if ( ! socket.connect ( "127.0.0.1", 30666 ) )
        {
            throw SocketException ( "Could not bind to port." );
        }
        
        ProtoMsgHandle msghandle;
        msghandle.initHandles();
        
        while (true) {
            
            try {
                
            } catch (...) {
                
            }
            string msg = "client";
            socket.send(msg) ;

            cout << endl << "recieve the packet" << endl;
            
            HHHeader header;
            socket.recv(&header, sizeof(header));
//            if(header.flag != 0xffff){
//                // 读完所有坏数据？ // TODO
//                char tmp[10*1024];
//                socket.recv(&tmp, sizeof(tmp));
//                continue;
//            }
            
            int messageSize = header.msg_length;
            char protoMsgArray[messageSize];
            socket.recv(&protoMsgArray, (int)sizeof(protoMsgArray));
            
            const ::google::protobuf::Descriptor*descriptor =person::descriptor();
            const google::protobuf::Message* prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
            
            google::protobuf::Message* msgProtobuf = prototype->New();
            bool ret = msgProtobuf->ParseFromArray(protoMsgArray, (int)sizeof(protoMsgArray));
            if (ret == false)
            {
                continue;
            }
            
            person *person = static_cast<class person*>(msgProtobuf) ;
            
            cout << "person->age()="<<person->age() << endl;
            cout << "person->userid()="<<person->userid() << endl;
            cout << "person->name()="<<person->name() << endl;
            
            
            
            //msghandle.handle(tmp);
            
//            HHHeader header;
//            socket.recv(&header, sizeof(header));
            
//            cout << "flag: " << header.flag << endl;
//            cout << "packet index: " << header.seq << endl;
//            cout << "msg_length: " << header.msg_length << endl;
//            cout << "type: " << header.type << endl;
//            cout << "reserved: " << header.reserved << endl;
//            
//            byte* body = new byte[header.msg_length];
//            socket.recv(body, header.msg_length);
//            
//            
//            cout << "body: " << body << endl;
            
            sleep(1);
        }
    }
    catch ( SocketException& e )
    {
        std::cout << "Exception was caught:" << e.description() << "\n";
    }
    
    return 0;
}

