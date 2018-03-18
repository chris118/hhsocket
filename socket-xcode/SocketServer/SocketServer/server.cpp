#include "server.h"
#include "db/sqlite3pp.h"

using namespace std;

//Actually allocate clients
vector<Client> Server::clients;

Server::Server(Config config) {
    m_config = config;

    //Initialize static mutex from HHThread
    HHThread::InitMutex();
    try
    {
        // Create the socket
        if ( ! serverSock.create() )
        {
            HHLOG("Could not create server socket.");
            throw SocketException ( "Could not create server socket." );
        }

        if ( ! serverSock.bind(m_config.port))
        {
            HHLOG("Could not bind to port.");
            throw SocketException ( "Could not bind to port." );
        }

        if ( ! serverSock.listen() )
        {
            HHLOG("Could not listen to socket.");
            throw SocketException ( "Could not listen to socket." );
        }
    }
    catch ( SocketException& e )
    {
        HHLOG2("Exception was caught: %s \nExiting.\n", e.description());
    }
}

Config Server::getConfig(){
    return m_config;
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
    worker_thread->Create((void *) Server::WorkThreadProc, this);

    Client *client;
    HHThread *client_thread;

    while(1) {

        client = new Client();
        client_thread = new HHThread();

        //block here waiting for client;
        bool ret = serverSock.accept(client->sock);
        
        HHPRINT("new client arrived,create the client thread!");
        if(ret == false) {
            HHLOG("Error on accept");
//            exit(0);
        }
        else {
            client_thread->Create((void *) Server::HandleClient, client);
        }
        sleep(2);
    }
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
        cout << "client->sock.recv"<< endl;
        memset(buffer, 0, sizeof buffer);
        n = client->sock.recv(buffer, sizeof buffer);
        cout << "n: " << n << endl;
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
            HHLOG2("Error while receiving message from client: %s", client->name);
        }else {
            HHPRINT("handle client msg");
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

    cout << " send to:" << "Client " << client.name << endl;
//    cout << "packetSize: " << packetSize << endl;
//    cout << "msgSize: " << msgSize << endl;

    char msgBuff[msgSize];
    msg.SerializeToArray(msgBuff,msgSize);

    // packet
//    char packetBuff[packetSize];
    char *packetBuff = new char[packetSize];
    memset(packetBuff, 0, packetSize);
    
    //头信息
    memcpy(packetBuff, &header, headerSize);
    //msg 信息
    memcpy(packetBuff + headerSize, msgBuff, msgSize);

    //TODO: 分小块发送
    bool ret = true;
    if(!client.sock.is_valid()){
        ret = false;
        HHLOG("invalid client socket >>>>>>");
    }else {
        ret = client.sock.send(packetBuff, packetSize);
        if(!ret){
            cout << "socket send error !" << endl;
        }
    }
    
    delete []packetBuff;

    return ret;
}

void Server::SendToAll(int packet_index, AlarmInfo info) {
    //Acquire the lock
    HHThread::LockMutex("'SendToAll()'");
    HHPRINT2("total client number ", clients.size());
    for(size_t i=0; i<clients.size(); i++) {
        HHHeader header;
        header.flag = 0xffff;
        header.seq = packet_index;
        header.msg_length = info.ByteSize();//Message的字节数
        header.type = 1;
        header.reserved = 0;

        bool ret = SendPacket(clients[i], packet_index, info, header);
        if(ret == false){
            sleep(1);
        }
    }

    //Release the lock
    HHThread::UnlockMutex("'SendToAll()'");
}

//worker thread
void *Server::WorkThreadProc(void *args) {
    Server *server = (Server* )args;

    sqlite3pp::database db(server->getConfig().db_path.c_str());
    db.set_busy_timeout(1000*15);

    int packet_index = 0;
    while(1)
    {
        // query image
//        HHPRINT("-------query t_image by id---------");
        char sql_image[256];
        sprintf(sql_image, "SELECT id, width, height FROM t_image WHERE send = %d", 0);
        sqlite3pp::query qry_image(db, sql_image);
        for (auto v : qry_image) {
            int image_id, width, height, send;

            v.getter() >> image_id >> width >> height >> send;
//            cout << "image_id = " << image_id << endl;
//            cout << "width = " <<width << endl;
//            cout << "height = " << height << endl;

            //query alarm by image_id
//            HHPRINT("-------query alarm by image_id---------");
            char sql[256];
            sprintf(sql, "SELECT id, obj_type, timestamp, x, y, w, h,start_timestamp, end_timestamp, credibility, \
                             alarm_pic, alarm_vid, src_image FROM t_alarminfo WHERE image_id = %d", image_id);

            sqlite3pp::query qry(db, sql);
            for (auto v : qry) {
                int id, obj_type, timestamp, x, y, w, h, start_timestamp, end_timestamp;
                float credibility;
                string alarm_pic, alarm_vid, src_image;

                v.getter() >> id >> obj_type >> timestamp >> x >> y >> w
                >> h >> start_timestamp >> end_timestamp >> credibility
                >> alarm_pic >> alarm_vid >> src_image;

                if(send == 1){
                    continue;
                }

//                cout << "image_id = " << image_id << endl;
//                cout << "id = " << id << endl;
//                cout << "obj_type = " <<obj_type << endl;
//                cout << "timestamp = " << timestamp << endl;
//                cout << "x = " << x << endl;
//                cout << "y = " << y << endl;
//                cout << "w = " << w << endl;
//                cout << "h = " << h << endl;
//                cout << "start_timestamp = " << start_timestamp << endl;
//                cout << "end_timestamp = " << end_timestamp << endl;
//                cout << "credibility = " << credibility << endl;
//                cout << "alarm_pic = " << alarm_pic << endl;
//                cout << "alarm_vid = " << alarm_vid << endl;
//                cout << "src_image = " << src_image << endl;

                //alarm_image
//                    std::ifstream ifs_alarm(alarm_pic);
                std::ifstream ifs_alarm("002.jpg");
                if(!ifs_alarm)
                {
                    cout << "Error open file..." << endl;
                    continue;
                }
                //If you really need it in a string you can initialize it the same way as the vector
                std::string alarm_image_data = std::string(std::istreambuf_iterator<char>(ifs_alarm), std::istreambuf_iterator<char>());
                ifs_alarm.close();

                // send alarm
                AlarmInfo info;
                info.set_image_id(image_id);
                info.set_image_width(width);
                info.set_image_height(height);

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

                info.set_alarm_vid("");
                info.set_src_image("");
                info.set_alarm_pic(alarm_image_data);

                Server::SendToAll(packet_index, info);
                packet_index++;
            }

//            //update status
//            char sql_update[1024];
//            sprintf(sql_update, "UPDATE t_image SET send = 1 WHERE id = %d", image_id);
//            db.execute(sql_update);
        }
        sleep(1);
    }
    //End thread
    return NULL;
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
    HHLOG("Client id not found.");
    return -1;
}
