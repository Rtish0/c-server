#ifndef _HTTP_SERVER_H
#define _HTTP_SERVER_H

#include <winsock2.h>
#include "http_operations.h"
#include "routes.h"
#include "logger.h"

typedef struct ServerHttp {
  ServerLogger logger;
  Route *router;
  SOCKET socket;
  int port;
} ServerHttp;

extern int init_server(ServerHttp *server, ServerLogger logger, int port);
extern int server_add_route(ServerHttp *server, char *path, HttpResponse *res);
extern int server_listen(ServerHttp *server);
extern int close_server(ServerHttp *server);

#endif // _HTTP_SERVER_H