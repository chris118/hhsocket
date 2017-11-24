#include "server.h"


using namespace std;

//Actually allocate clients
vector<Client> Server::clients;

Server::Server() {
    
    //Initialize static mutex from HHThread
    HHThread::InitMutex();
    try
    {
        // Create the socket
        if ( ! serverSock.create() )
        {
            throw SocketException ( "Could not create server socket." );
        }
        
        if ( ! serverSock.bind(PORT))
        {
            throw SocketException ( "Could not bind to port." );
        }
        
        if ( ! serverSock.listen() )
        {
            throw SocketException ( "Could not listen to socket." );
        }
    }
    catch ( SocketException& e )
    {
        LOG2("Exception was caught: %s \nExiting.\n", e.description());
    }
}

/*
	AcceptAndDispatch();
 
	Main loop:
 Blocks at accept(), until a new connection arrives.
 When it happens, create a new thread to handle the new client.
 */
void Server::AcceptAndDispatch() {
    
    Client *client;
    HHThread *t;
    
    while(1) {
        
        client = new Client();
        t = new HHThread();
        
        //Blocks here;
        bool ret = serverSock.accept(client->sock);
        
        if(ret == false) {
            LOG("Error on accept");
        }
        else {
            t->Create((void *) Server::HandleClient, client);
        }
    }
}

//Static
void *Server::HandleClient(void *args) {
    
    //Pointer to accept()'ed Client
    Client *client = (Client *) args;
    char buffer[256-25], message[256];
    int index;
    int n;
    
    //Add client in Static clients <vector> (Critical section!)
    HHThread::LockMutex((const char *) client->name);
    
    //Before adding the new client, calculate its id. (Now we have the lock)
    client->SetId((int)Server::clients.size());
    sprintf(buffer, "Client n.%d", client->id);
    client->SetName(buffer);
    cout << "Adding client with id: " << client->id << endl;
    Server::clients.push_back(*client);
    
    HHThread::UnlockMutex((const char *) client->name);
    
    int packet_index = 0;
    while(1)
    {
        memset(buffer, 0, sizeof buffer);
        n = client->sock.recv(buffer, sizeof buffer);
        
        //Client disconnected?
        if(n == 0) {
            cout << "Client " << client->name << " diconnected" << endl;
            //      close(c->sock);
            client->sock.close();
            
            //Remove client in Static clients <vector> (Critical section!)
            HHThread::LockMutex((const char *) client->name);
            
            index = Server::FindClientIndex(client);
            cout << "Erasing user in position " << index << " whose name id is: "
            << Server::clients[index].id << endl;
            Server::clients.erase(Server::clients.begin() + index);
            
            HHThread::UnlockMutex((const char *) client->name);
            
            break;
        }
        else if(n < 0) {
            LOG2("Error while receiving message from client: %s", client->name);
        }
        else {
            //Message received. Send to all clients.
            snprintf(message, sizeof message, "<%s>: %s", client->name, buffer);
            cout << "Will send to all: " << message << endl;
            
            Server::SendToAll(packet_index);
        }
        
        packet_index++;
    }
    
    //End thread
    return NULL;
}

void Server::SendPacket(Client &client, int packet_index,
                        google::protobuf::Message &msg, HHHeader header){
    
    int headerSize = sizeof(HHHeader);
    int msgSize= msg.ByteSize();
    int packetSize = headerSize + msgSize;
    
    char msgBuff[msgSize];
    msg.SerializeToArray(msgBuff,msgSize);
   
    // packet
    char packetBuff[packetSize];
    //头信息
    memcpy(packetBuff, &header, headerSize);
    //msg 信息
    memcpy(packetBuff + headerSize, msgBuff, msgSize);
    
    bool ret = client.sock.send(packetBuff, packetSize);
    if(!ret){
        cout << "socket send error !" << endl;
    }
}

void Server::SendToAll(int packet_index) {
    
    //Acquire the lock
    HHThread::LockMutex("'SendToAll()'");
    
    for(size_t i=0; i<clients.size(); i++) {
        
        person person;
        person.set_age(18);
        person.set_userid(200508);
        person.set_name("irons");
        
        HHHeader header;
        header.flag = 0xffff;
        header.seq = packet_index;
        header.msg_length = person.ByteSize();//Message的字节数
        header.type = 1;
        header.reserved = 0;

        SendPacket(clients[i], packet_index, person, header);
    }
    
    //Release the lock
    HHThread::UnlockMutex("'SendToAll()'");
}

void Server::ListClients() {
    for(size_t i=0; i<clients.size(); i++) {
        cout << clients.at(i).name << endl;
    }
}

/*
 Should be called when vector<Client> clients is locked!
 */
int Server::FindClientIndex(Client *c) {
    for(size_t i=0; i<clients.size(); i++) {
        if((Server::clients[i].id) == c->id) return (int) i;
    }
    LOG("Client id not found.");
    return -1;
}
