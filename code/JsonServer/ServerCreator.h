#pragma once 

#include "Server.h"
#include "JsonHttpServer.h"

enum ServerType
{
  JSON_SERVER = 0, 
  SOAP_SERVER, 
};

class ServerFactory {
public: 
  static Server* CreateServer(ServerType x) {
    switch (x) {
    case JSON_SERVER: 
      return JsonHttpServer::GetJsonServer();
      break; 

    default: 
         ucout << utility::string_t(U("Wrong Server Type = ")) << x << std::endl;
    }
    return nullptr; 
  }
};