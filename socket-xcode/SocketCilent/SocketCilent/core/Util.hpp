//
//  Util.hpp
// 
//
//  Created by xiaopeng.
//  Copyright  All rights reserved.
//
#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <ctime>
#include <sys/timeb.h>  

#ifndef UTIL
#define UTIL

using namespace std;

#define byte char

int API_TimeToString(string &strDateStr)
{
    //generate the name
    time_t timep;
    struct tm *p;
    time(&timep); /*当前time_t类型UTC时间*/
    p = localtime(&timep); /*转换为本地的tm结构的时间按*/
    p->tm_year = p->tm_year + 1900;
    p->tm_mon = p->tm_mon + 1;
    
    char chTmp[20];
    bzero(chTmp,sizeof(chTmp));
    snprintf(chTmp,sizeof(chTmp),"%04d-%02d-%02d-%02d-%02d-%02d",
             p->tm_year, p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
    
    strDateStr = chTmp;
    return 0;
}

int API_TimeToString2(string &strDateStr)
{
    //generate the name
    time_t timep;
    struct tm *p;
    time(&timep); /*当前time_t类型UTC时间*/
    p = localtime(&timep); /*转换为本地的tm结构的时间按*/
    p->tm_year = p->tm_year + 1900;
    p->tm_mon = p->tm_mon + 1;
    
    char chTmp[20];
    bzero(chTmp,sizeof(chTmp));
    snprintf(chTmp,sizeof(chTmp),"%04d-%02d-%02d",
             p->tm_year, p->tm_mon, p->tm_mday);
    
    strDateStr = chTmp;
    return 0;
}

string MakeOutputFileName(string ext)
{
    string time_str;
    API_TimeToString(time_str);
    string name = time_str + ext;
    
    return name;
}

string MakeOutputFolderName()
{
    string time_str;
    API_TimeToString2(time_str);
    
    return time_str;
}

int randomInt(int scope)
{
    srand((unsigned)time(NULL)); //用于保证是随机数
    return rand()%scope;  //用rand产生随机数并设定范围
}

char* GetLocalTimeStamp()
{
    // // 基于当前系统的当前日期/时间
    // time_t now = time(0);
    
    // // 把 now 转换为字符串形式
    // char* dt = ctime(&now);
    
    // return dt;
    struct  tm      *ptm;  
    struct  timeb   stTimeb;  
    static  char    szTime[19];  

    ftime(&stTimeb);  
    ptm = localtime(&stTimeb.time);  
    sprintf(szTime, "%02d-%02d %02d:%02d:%02d.%03d",  
            ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, stTimeb.millitm);  
    szTime[18] = 0;  
    return szTime; 
}

std::string ltos(long l)  
{  
    ostringstream os;  
    os<<l;  
    std::string result;  
    istringstream is(os.str());  
    is>>result;  
    return result;  
  
} 

std::string get_timestamp_string(){
    std::time_t t = std::time(0);
    return ltos(t);
}



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

#endif
