#include <string.h>
#include <curl/curl.h>
#include "http.h"

static void set_headers(CURL *curl, struct curl_slist *headers, char **settings, size_t settings_size)
{
    for (int i = 0; i < settings_size; i++)
    {
        headers = curl_slist_append(headers, settings[i]);
    }
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
}

static size_t response_cb(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct Response *res = (struct Response *)userp;
    res->body = realloc(res->body, res->size + realsize + 1);
    if (res->body == NULL)
    {
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }
    memcpy(&(res->body[res->size]), contents, realsize);
    res->size += realsize;
    res->body[res->size] = '\0';
    return realsize;
}
struct Response get(char *url, char **settings, size_t setting_size)
{
    CURL *curl;

    struct Response response;
    response.body = (char *)malloc(1);
    response.size = 0;
    response.status_code = 0;
    CURLcode curl_status = 0;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        set_headers(curl, headers, settings, setting_size);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, response_cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
        curl_status = curl_easy_perform(curl);
        if (curl_status != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(curl_status));
        }
        else
        {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status_code);
        }
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    return response;
}
struct Response delete(char *url, char **settings, size_t setting_size)
{
    CURL *curl;
    CURLcode curl_status = 0;

    struct Response response;
    response.body = (char *)malloc(1);
    response.size = 0;
    response.status_code = 0;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        set_headers(curl, headers, settings, setting_size);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, response_cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
        curl_status = curl_easy_perform(curl);
        if (curl_status != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(curl_status));
        }
        else
        {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status_code);
        }
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    return response;
}
struct Response post(char *url, char **settings, size_t setting_size, char *data)
{
    CURL *curl;
    CURLcode curl_status = 0;
    struct Response response;
    response.body = (char *)malloc(1);
    response.size = 0;
    response.status_code = 0;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        set_headers(curl, headers, settings, setting_size);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, response_cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
        curl_status = curl_easy_perform(curl);
        if (curl_status != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(curl_status));
        }
        else
        {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status_code);
        }
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    return response;
}

struct Response put(char *url, char **settings, size_t setting_size, char *data)
{
    CURL *curl;
    CURLcode curl_status = 0;
    struct Response response;
    response.body = (char *)malloc(1);
    response.size = 0;
    response.status_code = 0;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        set_headers(curl, headers, settings, setting_size);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, response_cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
        curl_status = curl_easy_perform(curl);
        if (curl_status != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(curl_status));
        }
        else
        {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response.status_code);
        }
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    return response;
}