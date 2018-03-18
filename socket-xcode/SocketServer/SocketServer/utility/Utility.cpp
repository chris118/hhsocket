//
//  Utility.cpp
//  hhsocket_client
//
//  Created by xiaopeng on 16/9/11.
//  Copyright © 2016年 hh. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Utility.h"



byte*  intToBytes( int value )
{
    byte* src = new byte[4];
    src[3] =  (byte) ((value>>24) & 0xFF);
    src[2] =  (byte) ((value>>16) & 0xFF);
    src[1] =  (byte) ((value>>8) & 0xFF);
    src[0] =  (byte) (value & 0xFF);
    
    return src;
}

byte* intToBytes2(int value)
{
    byte* src = new byte[4];
    src[0] = (byte) ((value>>24) & 0xFF);
    src[1] = (byte) ((value>>16)& 0xFF);
    src[2] = (byte) ((value>>8)&0xFF);
    src[3] = (byte) (value & 0xFF);
    return src;
}


int bytesToInt(byte* src, int offset) {
    int value;
    value = (int) ((src[offset] & 0xFF)
                   | ((src[offset+1] & 0xFF)<<8)
                   | ((src[offset+2] & 0xFF)<<16)
                   | ((src[offset+3] & 0xFF)<<24));
    return value;
}

int bytesToInt2(byte* src, int offset) {
    int value;
    value = (int) ( ((src[offset] & 0xFF)<<24)
                   |((src[offset+1] & 0xFF)<<16)
                   |((src[offset+2] & 0xFF)<<8)
                   |(src[offset+3] & 0xFF));
    return value;
}


byte toByte(char c) {
    std::string str ="0123456789ABCDEF";
    byte b = (byte) str.find(c);
    return b;
}

byte* hexStringToByte(std::string hex)
{
    int len = (hex.length() / 2);
    byte *result = new byte[len];
    const char* achar = hex.c_str();
    for (int i = 0; i < len; i++)
    {
        int pos = i * 2;
        result[i] = (byte) (toByte(achar[pos]) << 4 | toByte(achar[pos + 1]));
    }  
    return result;  
}
