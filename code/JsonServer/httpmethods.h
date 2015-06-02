#pragma once 
#include "stdafx.h"

using namespace web;
using namespace http;


//All Handler Methods 
void handle_put(http_request message);
void handle_post(http_request message);
void handle_delete(http_request message);
void handle_get(http_request message); 