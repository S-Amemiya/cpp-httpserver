#define BOOST_DATE_TIME_NO_LIB
#define BOOST_REGEX_NO_LIB
#define BOOST_ERROR_CODE_HEADER_ONLY
#define BOOST_SYSTEM_NO_LIB

#include <iostream>
#include <boost/network/protocol/http/server.hpp>

using namespace std;
namespace http = boost::network::http;

struct handler;
typedef http::server<handler> http_server;

struct handler {
  void operator() (http_server::request const &request,
    http_server::response &response) {
    response = http_server::response::stock_reply(
    http_server::response::ok, "Hello, world!");
  }

  void log(http_server::string_type const &info) {
    std::cerr << "ERROR: " << info << '\n';
  }
};

int main() {
  handler handler_;
  http_server::options options(handler_);
  http_server server_(
    options.address("0.0.0.0")
    .port("8000"));
  server_.run();
  return 0;
}
