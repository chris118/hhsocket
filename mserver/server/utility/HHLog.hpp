//
//  HHLog.hpp
//  hhsocket_client
//
//  Created by xiaopeng on 16/9/14.
//  Copyright © 2016年 hh. All rights reserved.
//

#ifndef HHLog_hpp
#define HHLog_hpp

#include <stdio.h>
#include <fstream>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>

//log文件路径
#define LOG_FILE_NAME "log.txt"
#define MAX_PATH 256

//启用开关
#define LOG_ENABLE

using namespace std;

class HHLog
{
public:
    static void GetLogFilePath(char* szPath)
    {
        getcwd(szPath, MAX_PATH);
        
//        GetModuleFileName( NULL, szPath, MAX_PATH ) ;
//        ZeroMemory(strrchr(szPath,'\\'), strlen(strrchr(szPath,'\\' ) )*sizeof(char)) ;
        strcat(szPath,"/");
        strcat(szPath,LOG_FILE_NAME);
    }
    //输出一个内容，可以是字符串(ascii)、整数、浮点数、布尔、枚举
    //格式为：[2011-11-11 11:11:11] aaaaaaa并换行
    template <class T>
    static void WriteLog(T x)
    {
        char szPath[MAX_PATH] = {0};
        GetLogFilePath(szPath);
        
        // print to consol
        cout << GetSystemTime() << x <<endl;
        
        ofstream fout(szPath,ios::app);
        fout.seekp(ios::end);
        fout << GetSystemTime() << x <<endl;
        fout.close();
    }
    
    //输出2个内容，以等号连接。一般用于前面是一个变量的描述字符串，后面接这个变量的值
    template<class T1,class T2>
    static void WriteLog2(T1 x1,T2 x2)
    {
        // print to consol
        cout << GetSystemTime() << x1 <<" = "<<x2<<endl;
        
        char szPath[MAX_PATH] = {0};
        GetLogFilePath(szPath);
        ofstream fout(szPath,ios::app);
        fout.seekp(ios::end);
        fout << GetSystemTime() << x1 <<" = "<<x2<<endl;
        fout.close();
    }
    
    //输出一行当前函数开始的标志,宏传入__FUNCTION__
    template <class T>
    static void WriteFuncBegin(T x)
    {
        char szPath[MAX_PATH] = {0};
        GetLogFilePath(szPath);
        ofstream fout(szPath,ios::app);
        fout.seekp(ios::end);
        fout << GetSystemTime() << "    --------------------"<<x<<"  Begin--------------------" <<endl;
        fout.close();
    }
    
    //输出一行当前函数结束的标志，宏传入__FUNCTION__
    template <class T>
    static void WriteFuncEnd(T x)
    {
        char szPath[MAX_PATH] = {0};
        GetLogFilePath(szPath);
        ofstream fout(szPath,ios::app);
        fout.seekp(ios::end);
        fout << GetSystemTime() << "--------------------"<<x<<"  End  --------------------" <<endl;
        fout.close();
    }
    
    
private:
    //获取本地时间，格式如"[2011-11-11 11:11:11] ";
    static string GetSystemTime()
    {
        time_t tNowTime;
        time(&tNowTime);
        tm* tLocalTime = localtime(&tNowTime);
        char szTime[30] = {'\0'};
        strftime(szTime, 30, "[%Y-%m-%d %H:%M:%S] ", tLocalTime);
        string strTime = szTime;
        return strTime;
    }
    
};

#ifdef LOG_ENABLE

//用下面这些宏来使用本文件
#define LOG(x)              HHLog::WriteLog(x);          //括号内可以是字符串(ascii)、整数、浮点数、bool等
#define LOG2(x1,x2)     HHLog::WriteLog2(x1,x2);
#define LOG_FUNC        LOG(__FUNCTION__)               //输出当前所在函数名
#define LOG_LINE        LOG(__LINE__)                       //输出当前行号
#define LOG_FUNC_BEGIN  HHLog::WriteFuncBegin(__FUNCTION__);     //形式如：[时间]"------------FuncName  Begin------------"
#define LOG_FUNC_END     HHLog::WriteFuncEnd(__FUNCTION__);      //形式如：[时间]"------------FuncName  End------------"

#else

#define LOG(x)
#define LOG2(x1,x2)
#define LOG_FUNC
#define LOG_LINE
#define LOG_FUNC_BEGIN
#define LOG_FUNC_END

#endif




#endif /* HHLog_hpp */
