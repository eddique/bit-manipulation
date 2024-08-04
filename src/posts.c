#include "http.h"
#include "posts.h"
#include <stdlib.h>
#include <stdio.h>
void list_posts()
{
    char *url = "https://jsonplaceholder.typicode.com/posts";
    char *settings[] = {
        "Content-Type: application/json; charset=utf-8",
        "Authorization: Bearer TOKEN"};
    struct Response response = get(url, settings, 2);
    printf("@GET /posts %ld\n", response.status_code);
    printf("Data:\n%s\n", response.body);
    free(response.body);
}
void get_post(int post)
{
    char *base_url = "https://jsonplaceholder.typicode.com/posts/";
    char url[256];
    snprintf(url, sizeof(url), "%s%d", base_url, post);
    char *settings[] = {
        "Content-Type: application/json; charset=utf-8",
        "Authorization: Bearer TOKEN"};
    struct Response response = get(url, settings, 2);
    printf("@GET /posts/%d %ld\n", post, response.status_code);
    printf("Data:\n%s\n", response.body);
    free(response.body);
}
void create_post()
{
    char *url = "https://jsonplaceholder.typicode.com/posts";
    char *settings[] = {
        "Content-Type: application/json; charset=utf-8",
        "Authorization: Bearer TOKEN"};
    char *data = "{\"title\":\"Hello, World!\",\"body\":\"Hello, World from C!\",\"userId\":1}";
    struct Response response = post(url, settings, 2, data);
    printf("@POST /posts %ld\n", response.status_code);
    printf("Data:\n%s\n", response.body);
    free(response.body);
}
void update_post(int post)
{
    char *base_url = "https://jsonplaceholder.typicode.com/posts/";
    char url[256];
    snprintf(url, sizeof(url), "%s%d", base_url, post);
    char *settings[] = {
        "Content-Type: application/json; charset=utf-8",
        "Authorization: Bearer TOKEN"};
    char *data = "{\"title\":\"Hello, World!\",\"body\":\"Hello, World from C!\",\"userId\":1}";
    struct Response response = put(url, settings, 2, data);
    printf("@PUT /posts/%d %ld\n", post, response.status_code);
    printf("Data:\n%s\n", response.body);
    free(response.body);
}
void delete_post(int post)
{
    char *base_url = "https://jsonplaceholder.typicode.com/posts/";
    char url[256];
    snprintf(url, sizeof(url), "%s%d", base_url, post);

    char *settings[] = {
        "Content-Type: application/json; charset=utf-8",
        "Authorization: Bearer TOKEN"};
    struct Response response = delete (url, settings, 2);
    printf("@DELETE /posts/%d %ld\n", post, response.status_code);
    printf("Data:\n%d\n", post);
    free(response.body);
}