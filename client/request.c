#include "dict.h"
#include <curl/curl.h>

void writefunc(void *ptr, size_t size, size_t nmemb, char *response) {
    strcpy(response, (char *)ptr);
}

int request(char *query, char *response) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://dict-cli.herokuapp.com/graphql");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/graphql");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, query);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    } else
        return false;
    return true;
}