#include <iostream>
#include "hhthread.h"
#include "server.h"
#include "global.hpp"
#include "iniFile.hpp"

using namespace std;

Config config;
bool InitConfig(){
    IniFile ini("config.ini");
    unsigned int dwSize = 0;
    char sSection1[16] = "SERVER";
    
    // config.ip = ini.readstring(sSection1, "ip", "error", dwSize);
    config.port = ini.readinteger(sSection1, "port", 0);
    config.db_path = ini.readstring(sSection1, "db_path", "error", dwSize);

    cout << "----------config----------" << endl;
    cout << "port: " << config.port << endl;
    cout << "db_path:" << config.db_path << endl;

    return true;
}

int main() {
  InitConfig();

  cout << "server started!" << endl;

  Server *s;
  s = new Server(config);

  //Main loop
  s->AcceptAndDispatch();

  return 0;
}
