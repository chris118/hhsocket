#ifndef _server_h_
#define _server_h_

#include <iostream>
#include <vector>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <sys/socket.h>
#include <netinet/in.h>

#include "hhthread.h"
#include "client.h"

#include "HHLog.hpp"
#include "hhpacket.hpp"
#include "Utility.h"
#include "hhmessagesender.hpp"
#include "socket_base/Socket.h"
#include "socket_base/SocketException.h"

#define PORT 30666

using namespace std;

enum ErrorCode {
    NetError,
    FileNotExist
};
class Server {

  private:
    static vector<Client> clients;

    //Socket stuff
    Socket serverSock, clientSock;
    struct sockaddr_in serverAddr, clientAddr;
    char buff[256];

  public:
    Server();
    void AcceptAndDispatch();
    static void * HandleClient(void *args);

  private:
    static void ListClients();
    static void SendToAll(int packet_index);
    static void SendPacket(Client &client, int packet_index, google::protobuf::Message &msg, HHHeader header);
    static int FindClientIndex(Client *c); 
};

#endif
