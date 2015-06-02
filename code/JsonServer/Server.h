/****************************** Module Header ******************************\
* Module Name:  Server.h
* Project	 :  BloggerJsonService
* Description:	Provides the interface for the HTTP Server LIstener
\***************************************************************************/

#ifndef __SERVER_H__
#define __SERVER_H__

#include "stdafx.h"
//Forward declarations 
using namespace utility;
class string;


class Server {
public:
	virtual bool InitializeServerAtAddress(const utility::string_t& uri) = 0;
	virtual void Run() = 0;
	virtual ~Server(){}
};
#endif 
