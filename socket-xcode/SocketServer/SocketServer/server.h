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

#include "hhlog.hpp"
#include "HHPacket.hpp"
#include "Utility.h"
#include "global.hpp"
#include "socket_base/Socket.h"
#include "socket_base/SocketException.h"
#include "alarm.pb.h"

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
    Config m_config;
  public:
    Server(Config config);
    void AcceptAndDispatch();
    Config getConfig(); 

  private:
    
    static void * WorkThreadProc(void *args);
    static void * HandleClient(void *args);
    static void SendToAll(int packet_index, AlarmInfo info);
    static bool SendPacket(Client &client, int packet_index, google::protobuf::Message &msg, HHHeader header);
    static void ListClients();
    static int FindClientIndex(Client *c);
};

#endif
