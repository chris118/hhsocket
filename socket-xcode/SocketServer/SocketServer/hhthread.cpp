#include "hhthread.h"

using namespace std;

//Need to actually "allocate" static member
pthread_mutex_t HHThread::mutex;

HHThread::HHThread() {
}

int HHThread::Create(void *Callback, void *args) {
  int tret=0;
 
  //Supercreepy typecast
  tret = pthread_create(&this->tid, NULL, (void *(*)(void *))Callback, args);

  if(tret) { 
    cerr << "Error while creating threads." << endl;
    return tret;
  }
  else {
//    cout << "Thread successfully created." << endl;
    return 0;
  }
}

int HHThread::Join() {
  pthread_join(this->tid, NULL);
  return 0;
}

int HHThread::InitMutex() {
  
  if(pthread_mutex_init(&HHThread::mutex, NULL) < 0) {
    cerr << "Error while initializing mutex" << endl;
    return -1;
  }
  else {
    cout << "Mutex initialized." << endl;
    return 0;
  }
}

/*
    LockMutex():
		Blocks until mutex becomes available
*/
int HHThread::LockMutex(const char *identifier) {
//  cout << identifier << " is trying to acquire the lock..." << endl;
  if(pthread_mutex_lock(&HHThread::mutex) == 0) {
//    cout << identifier << " acquired the lock!" << endl;
    return 0;
  }
  else {
   cerr << "Error while " << identifier << " was trying to acquire the lock" << endl;
   return -1;
  }
}

int HHThread::UnlockMutex(const char *identifier) {
//  cout << identifier << " is trying to release the lock..." << endl;
  if(pthread_mutex_unlock(&HHThread::mutex) == 0) {
//    cout << identifier << " released the lock!" << endl;
    return 0;
  }
  else {
   cerr << "Error while " << identifier << " was trying to release the lock" << endl;
   return -1;
  }
}
