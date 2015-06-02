#include "stdafx.h"
#include "JsonHttpServer.h"
#include "httpmethods.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

using namespace std;

JsonHttpServer* JsonHttpServer::_jsonServer = nullptr; 


JsonHttpServer* JsonHttpServer::GetJsonServer()
{
  if (_jsonServer == nullptr) {
    _jsonServer = new  JsonHttpServer(); 
  }

  return _jsonServer; 
}

void on_initialize(const string_t& address)
{
	// Build our listener's URI from the configured address and the hard-coded path "blackjack/dealer"

	uri_builder uri(address);
	//uri.append_path(U("/TestExecution"));

	auto addr = uri.to_uri().to_string();
	//jsonHttpHandler = std::unique_ptr<JsonHttpServer>(new JsonHttpServer(addr));

  //jsonHttpHandler->InitializeServer();

	ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

	return;
}


void on_shutdown()
{
	
	return;
}


bool JsonHttpServer::InitializeServerAtAddress(const utility::string_t& address)
{

  // Build our listener's URI from the configured address and the hard-coded path
  //"blackjack/dealer"

  uri_builder uri(address);
  //uri.append_path(U("/TestExecution"));

  auto addr = uri.to_uri().to_string();
  _listener = new http_listener(addr); 

  //Add support for appropriate methods
  _listener->support(methods::GET, handle_get);
  //_listener.support(methods::PUT, handle_get);
  //_listener.support(methods::POST, handle_get);
  //_listener.support(methods::DEL, handle_get);

  ucout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;
  return true; 
}


bool JsonHttpServer::InitializejsonHttpHandler(utility::string_t url)
{
	return true;

}

void JsonHttpServer::Run()
{
  _jsonServer->open().wait();
}

void JsonHttpServer::Stop()
{
  _jsonServer->close().wait();
}


