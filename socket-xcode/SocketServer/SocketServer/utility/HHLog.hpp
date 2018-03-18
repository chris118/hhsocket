//
//  HHLog.hpp
// 
//
//  Created by xiaopeng.
//  Copyright  All rights reserved.
//

#ifndef hhlog_hpp
#define hhlog_hpp

#include <stdio.h>
#include <fstream>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <time.h>
#include <sys/timeb.h>  

#define LOG_FILE_NAME "log.txt"
#define MAX_PATH 256

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

    template <class T>
    static void PrintLog(T x)
    {
        cout << GetSystemTime() << " " << x << endl;
    }

    template<class T1,class T2>
    static void PrintLog2(T1 x1,T2 x2)
    {
        cout << GetSystemTime() << " " << x1 <<" = "<< x2 << endl;
    }

    template <class T>
    static void WriteLog(T x)
    {
        char szPath[MAX_PATH] = {0};
        GetLogFilePath(szPath);
        
        ofstream fout(szPath,ios::app);
        fout.seekp(ios::end);
        fout << GetSystemTime() << x <<endl;
        cout << GetSystemTime() << x <<endl;

        fout.close();
    }
    
    template<class T1,class T2>
    static void WriteLog2(T1 x1,T2 x2)
    {
        char szPath[MAX_PATH] = {0};
        GetLogFilePath(szPath);
        ofstream fout(szPath,ios::app);
        fout.seekp(ios::end);
        fout << GetSystemTime() << x1 <<" = "<<x2<<endl;
        cout << GetSystemTime() << x1 <<" = "<<x2<<endl;
        fout.close();
    }
    
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
    static string GetSystemTime()
    {
        // time_t tNowTime;
        // time(&tNowTime);
        // tm* tLocalTime = localtime(&tNowTime);
        // char szTime[30] = {'\0'};
        // strftime(szTime, 30, "[%Y-%m-%d %H:%M:%S] ", tLocalTime);

        struct  tm      *ptm;  
        struct  timeb   stTimeb;  
        static  char    szTime[21];

        ftime(&stTimeb);  
        ptm = localtime(&stTimeb.time);  
        sprintf(szTime, "[%02d-%02d %02d:%02d:%02d.%03d]",
            ptm->tm_mon+1, ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, stTimeb.millitm);  
        szTime[20] = 0;

        string strTime = szTime;
        return strTime;
    }
    
};

#ifdef LOG_ENABLE

#define HHPRINT(x)        HHLog::PrintLog(x);  
#define HHPRINT2(x1,x2)     HHLog::PrintLog2(x1,x2);
#define HHLOG(x)              HHLog::WriteLog(x);          
#define HHLOG2(x1,x2)     HHLog::WriteLog2(x1,x2);
#define HHLOG_FUNC        LOG(__FUNCTION__)               
#define HHLOG_LINE        LOG(__LINE__)                       
#define HHLOG_FUNC_BEGIN  HHLog::WriteFuncBegin(__FUNCTION__);     
#define HHLOG_FUNC_END     HHLog::WriteFuncEnd(__FUNCTION__);

#else

#define HHLOG(x)
#define HHLOG2(x1,x2)
#define HHLOG_FUNC
#define HHLOG_LINE
#define HHLOG_FUNC_BEGIN
#define HHLOG_FUNC_END

#endif




#endif /* hhlog_hpp */
