//
//  ThreadPool.hpp
//
//
//  Created by xiaopeng.
//  Copyright  All rights reserved.
//

#pragma once
#include <deque>
#include <string>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

class Task
{
public:
    Task(void* arg = NULL, const std::string taskName = "")
    : arg_(arg)
    , taskName_(taskName)
    {
    }
    virtual ~Task()
    {
    }
    void setArg(void* arg)
    {
        arg_ = arg;
    }

    void setName(std::string name){
        taskName_ = name;
    }

    virtual int run() = 0;

protected:
    void*       arg_;
    std::string taskName_;
};


class ThreadPool
{
public:
    ThreadPool(int threadNum = 10);
    ~ThreadPool();

public:
    size_t addTask(Task *task);
    void removeTask(Task *task);
    void clearTask();
    void   stop();
    int    size();
    Task*  take();

private:
    int createThreads();
    static void* threadFunc(void * threadData);

private:
    ThreadPool& operator=(const ThreadPool&);
    ThreadPool(const ThreadPool&);

private:
    volatile  bool              isRunning_;
    int                         threadsNum_;
    pthread_t*                  threads_;

    std::deque<Task*>           taskQueue_;
    pthread_mutex_t             mutex_;
    pthread_cond_t              condition_;
};
