#ifndef _HTTP_STRUCTS_H
#define _HTTP_STRUCTS_H

/*
 * HTTP server request size constants
 */
#define MAX_HTTP_REQUEST_SIZE 65536
#define HTTP_PATH_SIZE 512
#define HTTP_VERSION_SIZE 10

#define HTTP_HEADER_KEY_SIZE 1024
#define HTTP_HEADER_VALUE_SIZE 4096

/*
 * HTTP server response size constants
 */
#define HTTP_RESPONSE_HEADER_SIZE 4096

typedef enum {
  STATUSCODE_OK = 0,
  STATUSCODE_CREATED,
  STATUSCODE_ACCEPTED,
  STATUSCODE_NO_CONTENT,
  STATUSCODE_BAD_REQUEST,
  STATUSCODE_UNAUTHORIZED,
  STATUSCODE_FORBIDDEN,
  STATUSCODE_NOT_FOUND,
  STATUSCODE_INTERNAL_ERROR,
  STATUSCODE_NOT_IMPLEMENTED
} StatusCode;

typedef struct {
  StatusCode code;
  char *body;
} HttpResponse;

// Create/Destroy reponse
extern int create_response(HttpResponse *res, StatusCode code, const char *body);
extern int destroy_response(HttpResponse *res);

typedef enum {
  HTTP_UNKNOWN = -1,
  HTTP_GET = 0,
  HTTP_POST,
  HTTP_PUT,
  HTTP_DELETE
} RequestMethod;

typedef struct {
  RequestMethod method;
  char path[HTTP_PATH_SIZE];
  char version[HTTP_VERSION_SIZE];
} HttpRequest;

// Create/Destroy request
extern int parse_request(HttpRequest *res, char *req_str);

#endif // _HTTP_STRUCTS_H