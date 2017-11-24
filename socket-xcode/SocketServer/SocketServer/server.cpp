#include "server.h"
#include "../db/sqlite3pp.h"

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
    
    //开启工作线程
    HHThread *worker_thread = new HHThread();
    worker_thread->Create((void *) Server::WorkThreadProc, NULL);
    
    
    Client *client;
    HHThread *client_thread;

    while(1) {
        
        client = new Client();
        client_thread = new HHThread();
        
        //Blocks here;
        
        bool ret = serverSock.accept(client->sock);
        
        if(ret == false) {
            LOG("Error on accept");
        }
        else {
            client_thread->Create((void *) Server::HandleClient, client);
        }
    }
}

//worker thread
void *Server::WorkThreadProc() {
    sqlite3pp::database db("./local.db");

    int packet_index = 0;
    while(1)
    {
        sqlite3pp::query qry(db, "SELECT id, obj_type, timestamp, x, y, w, h,\
                             start_timestamp, end_timestamp, credibility, \
                             alarm_pic, alarm_vid, src_image, send FROM t_alarminfo");
        for (auto v : qry) {
            int id, obj_type, timestamp, x, y, w, h, start_timestamp, end_timestamp, send;
            float credibility;
            string alarm_pic, alarm_vid, src_image;
            
            v.getter() >> id >> obj_type >> timestamp >> x >> y >> w
            >> h >> start_timestamp >> end_timestamp >> credibility
            >> alarm_pic >> alarm_vid >> src_image >> send;
            
           
            cout << "id = " << id << endl;
            cout << "obj_type = " <<obj_type << endl;
            cout << "timestamp = " << timestamp << endl;
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;
            cout << "w = " << w << endl;
            cout << "h = " << h << endl;
            cout << "start_timestamp = " << start_timestamp << endl;
            cout << "end_timestamp = " << end_timestamp << endl;
            cout << "credibility = " << credibility << endl;
            
            //read file
            std::ifstream ifs("002.jpg");
//            std::ifstream ifs("1.txt");

            if(!ifs)
            {
                cout << "Error open file..." << endl;
                continue;
            }

            
            //If you really need it in a string you can initialize it the same way as the vector
            std::string src_image_data = std::string(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
//            std::for_each(src_image_data.begin(), src_image_data.end(), [](char c) { std::cout << c; });

            
//            ifstream fin;
//            fin.open("002.jpg", ios_base::binary);
//            if (!fin.is_open())
//            {
//                cout << "Error open file..." << endl;
//            }
//            fin.seekg(0, ios::end);
//            long fsize = fin.tellg();
//            char* pfile = new char[fsize];
//            fin.read(pfile, fsize);
            
            // send alarm
            AlarmInfo info;
            info.set_id(id);
            info.set_obj_type(obj_type);
            info.set_timestamp(timestamp);
            info.set_x(x);
            info.set_y(y);
            info.set_w(w);
            info.set_h(h);
            info.set_start_timestamp(start_timestamp);
            info.set_end_timestamp(end_timestamp);
            info.set_credibility(credibility);
            
            info.set_src_image(src_image_data);
//            info.set_src_image("123");
//            info.set_alarm_pic("456");
//            info.set_alarm_vid("789");
        

            Server::SendToAll(packet_index, info);
            packet_index++;
            
            ifs.close();
//            if(pfile){
//                delete[] pfile;
//            }
            
            // update status
            //db.execute("UPDATE t_alarminfo SET send = 1 WHERE id = 478");
        }
        sleep(5);
    }
    
    //End thread
    return NULL;
}


//client thread
void *Server::HandleClient(void *args) {
    
    //Pointer to accept()'ed Client
    Client *client = (Client *) args;
    char buffer[256-25];
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
    }
    
    //End thread
    return NULL;
}

bool Server::SendPacket(Client &client, int packet_index,
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
    cout << "msgSize: " << msgSize << endl;
    
    bool ret = client.sock.send(packetBuff, packetSize);
    if(!ret){
        cout << "socket send error !" << endl;
        return false;
    }
    return true;
}

void Server::SendToAll(int packet_index, AlarmInfo info) {
    
    //Acquire the lock
    HHThread::LockMutex("'SendToAll()'");
    
    for(size_t i=0; i<clients.size(); i++) {
        
        cout << " send to:" << "Client " << clients[i].name << endl;
        
        HHHeader header;
        header.flag = 0xffff;
        header.seq = packet_index;
        header.msg_length = info.ByteSize();//Message的字节数
        header.type = 1;
        header.reserved = 0;

        SendPacket(clients[i], packet_index, info, header);
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





//        //Message received. Send to all clients.
//        snprintf(message, sizeof message, "<%s>: %s", client->name, buffer);
//        cout << "Will send to all: " << message << endl;
//
//        Server::SendToAll(packet_index);



//        memset(buffer, 0, sizeof buffer);
//        n = client->sock.recv(buffer, sizeof buffer);
//
//        //Client disconnected?
//        if(n == 0) {
//            cout << "Client " << client->name << " diconnected" << endl;
//            //      close(c->sock);
//            client->sock.close();
//
//            //Remove client in Static clients <vector> (Critical section!)
//            HHThread::LockMutex((const char *) client->name);
//
//            index = Server::FindClientIndex(client);
//            cout << "Erasing user in position " << index << " whose name id is: "
//            << Server::clients[index].id << endl;
//            Server::clients.erase(Server::clients.begin() + index);
//
//            HHThread::UnlockMutex((const char *) client->name);
//
//            break;
//        }
//        else if(n < 0) {
//            LOG2("Error while receiving message from client: %s", client->name);
//        }
//        else {
//            //Message received. Send to all clients.
//            snprintf(message, sizeof message, "<%s>: %s", client->name, buffer);
//            cout << "Will send to all: " << message << endl;
//
//            Server::SendToAll(packet_index);
//        }

//        packet_index++;

//        sleep(2);
