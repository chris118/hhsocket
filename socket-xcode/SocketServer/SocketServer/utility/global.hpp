//
//  global.hpp
// 
//
//  Created by xiaopeng.
//  Copyright  All rights reserved.
//

#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fstream>
#include <iostream>
#include <signal.h>
#include <time.h>
#include <unistd.h>

#pragma once 

#ifndef GLOBAL
#define GLOBAL

using namespace std;

struct Config
{
    string ip;
    int port;
    string db_path;
};
#endif
