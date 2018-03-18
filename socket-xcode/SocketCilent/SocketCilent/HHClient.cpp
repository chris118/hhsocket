//
//  HHClient.cpp
//  CallBackDemo
//
//  Created by Chris on 2017/10/9.
//  Copyright © 2017年 putao. All rights reserved.
//

#include <stdio.h>
#include "HHClient.hpp"
#include "HHClientImpl.hpp"

HHClientAPI* client = NULL;
HHClientAPI* hhclient::HHClientAPI_Create(HHlientCallback * callback){
    cout << "HHClientAPI_Create client: " << client << endl;
    client = new HHClientImpl(callback);
    return client;
}

void hhclient::HHClient_Destroy(HHClientAPI* client) {
    cout << "HHClient_Destroy client: " << client << endl;
    ((HHClientImpl*)client)->Logout();
    if(client){
      delete client;
      client = NULL;
    }
}
