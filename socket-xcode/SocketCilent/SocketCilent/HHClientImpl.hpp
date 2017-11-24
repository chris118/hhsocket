//
//  HHClientImpl.cpp
//  CallBackDemo
//
//  Created by Chris on 2017/10/9.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>
#include <iostream>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include "HHClient.hpp"
#include "core/ThreadPool.h"
#include "HHAlarmTask.hpp"

using namespace hhclient;
using namespace std;


class HHClientImpl: public HHClientAPI {
    
public:
    HHClientImpl(HHlientCallback * callback) {
        m_callback = callback;
        task = new HHAlarmTask(callback);
        task->setArg(m_callback);
    }
    
    ~HHClientImpl(){
        if(task){
            delete task;
        }
    }
    
    HHResult Login(string ip, int port) {

        //try to connect server
        if ( ! socket.create() )
        {
            return NET_ERROR;
        }
        
        if ( ! socket.connect ( ip, port ) )
        {
            return NET_ERROR;
        }
        
        task->setSocket(socket);
        thread_pool.addTask(task);
    
        return OK;
    }
    
private:
    ThreadPool thread_pool;
    HHAlarmTask *task;
    HHlientCallback * m_callback;
    Socket socket;
};
