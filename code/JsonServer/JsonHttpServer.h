#ifndef __JSON_HTTP_SERVER__
#define __JSON_HTTP_SERVER__

//Forward
#include "stdafx.h"
#include "Server.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;
using std::string;
using namespace http;

class JsonHttpServer : public Server{

private: 
  JsonHttpServer() :_running(false), _initialized(false), _listener(nullptr){}
  //JsonHttpServer(utility::string_t url);
public:
  static JsonHttpServer* GetJsonServer(); 
  virtual bool InitializeServerAtAddress(const utility::string_t& uri);
	virtual void Run();
	void Stop();
	bool IsRunning(){ return _running; }
	bool IsInitialized() { return _initialized; }
	pplx::task<void> open() { return _listener->open(); }
	pplx::task<void> close() { return _listener->close(); }

private: //private methods
	bool InitializejsonHttpHandler(utility::string_t url);
	bool InitializeRequestHandlers();


private: //For private variables 
	bool _running;
	bool _initialized;
	http_listener* _listener;
  static JsonHttpServer* _jsonServer; 

};
#endif