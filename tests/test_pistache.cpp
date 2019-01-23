#include <iostream>
#include "pistache/endpoint.h"

using namespace Pistache;

class HelloHandler : public Http::Handler {
public:

  HTTP_PROTOTYPE(HelloHandler)

  void onRequest(const Http::Request& request, Http::ResponseWriter response) {
    if (request.method() == Http::Method::Get){
      std::cout << "IT was a get request" << std::endl;
    } else if( request.method() == Http::Method::Post) {
      std::cout << "BODY:" << std::endl;
      std::cout << request.body() << std::endl;
    }
    response.send(Pistache::Http::Code::Ok, "Hello World\n");
  }
};

int main() {
  constexpr int PORT = 9080;
  Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(PORT));
  auto opts = Pistache::Http::Endpoint::options()
    .threads(1);

  Http::Endpoint server(addr);
  server.init(opts);
  server.setHandler(Http::make_handler<HelloHandler>());

  std::cout << "Starting server at localhost:" << PORT << std::endl;
  server.serve();

  server.shutdown();
}
