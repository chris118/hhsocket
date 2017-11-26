#ifndef _hhthread_h_
#define _hhthread_h_

#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>

#include <cstdlib>

using namespace std;

class HHThread {
  public:
    pthread_t tid;

  private:
    static pthread_mutex_t mutex;

  public:
    HHThread();
    int Create(void *Callback, void *args);
    int Join();

    static int InitMutex();
    static int LockMutex(const char *identifier);
    static int UnlockMutex(const char *identifier);
};

#endif
