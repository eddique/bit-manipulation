#ifndef bit_manipulation_http_h
#include <stdlib.h>
struct Response
{
    long status_code;
    char *body;
    size_t size;
};

struct Response get(char *url, char **settings, size_t setting_size);
struct Response delete(char *url, char **settings, size_t setting_size);
struct Response put(char *url, char **settings, size_t setting_size, char *data);
struct Response post(char *url, char **settings, size_t setting_size, char *data);
#endif