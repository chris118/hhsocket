//
//  main.cpp
//  hhsocket_client
//
//  Created by xiaopeng on 16/9/5.
//  Copyright © 2016年 hh. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include "HHClient.hpp"

using namespace std;
using namespace hhclient;

class HHCallback: public HHlientCallback{
    void onAlarm(const HHAlarm &alarm) {
        cout << "-----------------onAlarm----------------------- " << endl;
        
        cout << "id " << alarm.id << endl;
        cout << "car_type " << alarm.car_type << endl;
        cout << "timestamp " << alarm.timestamp << endl;
        cout << "x " << alarm.coordinate[0] << ",";
        cout << "y " << alarm.coordinate[1] << ",";
        cout << "width " << alarm.coordinate[2] << ",";
        cout << "height " << alarm.coordinate[3] << endl;
        cout << "start " << alarm.start_timestamp << endl;
        cout << "end " << alarm.end_timestamp << endl;
        cout << "credibility " << alarm.credibility << endl;
        
        
//        cout << "alarm_pic_size " << alarm.alarm_pic_size << endl;
//        cout << "alarm_pic " << static_cast<const void *>(alarm.alarm_pic) << endl;
//        cout << "alarm_vid_size " << alarm.alarm_vid_size << endl;
//        cout << "alarm_vid " <<static_cast<const void *>(alarm.alarm_vid )<< endl;
//        cout << "src_image_size " << alarm.src_image_size << endl;
//        cout << "src_image " <<static_cast<const void *>(alarm.src_image )<< endl;
//
//        ofstream os("result.jpg",ios::binary);
//        os.write(alarm.alarm_pic, alarm.alarm_pic_size);
    }
};


int main(int argc, const char * argv[])
{
    
    HHCallback *callback = new HHCallback();
    
    HHClientAPI* client = HHClientAPI_Create(callback);
    HHResult ret = client->Login("127.0.0.1", 30666);
    if(ret != OK){
        cout << "login error" << endl;
    }
    
    printf("input 'q' to quit\n");
    char c;
    scanf("%c", &c);
    
    HHClient_Destroy(client);
    
    return 0;
}

