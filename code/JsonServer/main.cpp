#include "stdafx.h"
#include "Server.h"
#include "JsonHttpServer.h"
#include "ServerCreator.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;


extern void on_initialize(const string_t& address);
extern void on_shutdown(); 

//
// To start the server, run the below command with admin privileges:
// BlackJack_Server.exe <port>
// If port is not specified, will listen on 34568
//
#ifdef _MS_WINDOWS
int wmain(int argc, wchar_t *argv[])
#else
int main(int argc, char *argv[])
#endif
{
	/*
	// Periodically check if the service is stopping.
	JsonHttpServer* jsonServer = new JsonHttpServer();
	//Rohit: The main Work of the Service Starts here 		
	if (!jsonServer->IsInitialized()) {
		jsonServer->InitializeServer(U("http://localhost:8080/TestExecution")); 
	}
	if (!jsonServer->IsRunning()) {
		jsonServer->Run(); 
	}
	*/
	
  Server* myServer = ServerFactory::CreateServer(JSON_SERVER); 

  utility::string_t port = U("8080");

  utility::string_t address = U("http://localhost:");
  address.append(port);


  myServer->InitializeServerAtAddress(address); 
  myServer->Run(); 

	std::cout << "Server is running Press ENTER to exit." << std::endl;

	std::string line;
	std::getline(std::cin, line);

	on_shutdown();
	
	return 0;
}
