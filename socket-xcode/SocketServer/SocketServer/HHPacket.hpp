//
//  HHPacket.hpp
//  SocketServer
//
//  Created by xiaopeng on 2017/5/21.
//  Copyright © 2017年 PT. All rights reserved.
//

#include <string>
#include <stdio.h>
#include "utility/Utility.h"

#ifndef HHPACKET_h
#define HHPACKET_h

struct HHHeader
{
    int flag;
    int seq;
    int msg_length;
    int type;
    int reserved;
};


struct HHPacket
{
    HHHeader header;
    byte*   body;
};

#endif
