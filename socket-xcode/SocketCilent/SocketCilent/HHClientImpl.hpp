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
#include "core/HHLog.hpp"
#include "HHAlarmTask.hpp"

using namespace hhclient;
using namespace std;


class HHClientImpl: public HHClientAPI {

public:
    HHClientImpl(HHlientCallback * callback) {
        m_callback = callback;
    }

    ~HHClientImpl(){
        if(task){
            delete task;
            task = NULL;
        }
        if(socket){
            delete socket;
            socket = NULL;
        }
    }

    HHResult Login(string ip, int port) {

      socket = new Socket();
    //   socket->set_non_blocking(true);
        //try to connect server
        if ( ! socket->create() )
        {
            return NET_ERROR;
        }

        if ( ! socket->connect ( ip, port ) )
        {
            return NET_ERROR;
        }
        
        task = new HHAlarmTask(m_callback);
        task->setSocket(socket,ip, port);
        thread_pool.addTask(task);

        return OK;
    }

    int Logout(){
      if(task){
          task->stop();
      }
      if(socket){
          socket->close();
      }
        
        return 0;
    }
    

private:
    ThreadPool thread_pool;
    HHAlarmTask *task;
    HHlientCallback * m_callback;
    Socket* socket;
};
