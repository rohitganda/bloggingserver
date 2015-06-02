#include "stdafx.h"
#include "httpmethods.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;

using namespace std;



//
// A GET of the dealer resource produces a list of existing tables.
// 
void handle_get(http_request message)
{
  ucout << message.to_string() << endl;

  auto paths = http::uri::split_path(http::uri::decode(message.relative_uri().path()));
  if (paths.empty())
  {    
    message.reply(status_codes::OK, U("You've reached the main page for Server JsonHttpServer"));
    return;
  }
  else {
    utility::string_t resp(U("Requested URI = "));
    resp.append(paths[0].c_str());
    message.reply(status_codes::OK, resp);
  }

}

void handle_put(http_request message)
{
  //TODO: Implement the methods 
}

void handle_post(http_request message)
{
  //TODO: Implement the method
}

void handle_delete(http_request message)
{
  //TODO: Implement the method 
}
