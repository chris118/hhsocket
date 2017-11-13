#ifndef _client_h_
#define _client_h_

#include <iostream>

#include <cstdio>
#include <cstdlib>

#include "socket_base/Socket.h"
#include "socket_base/SocketException.h"

#define MAX_NAME_LENGHT 20

using namespace std;

class Client {
  public:
    char *name;
    int id;

    //Socket stuff
    Socket sock;

  public:
    Client();
    void SetName(const char *name);
    void SetId(int id);
};

#endif
