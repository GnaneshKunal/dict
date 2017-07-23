#include "dict.h"
#include <curl/curl.h>

int request(char *query, char *response) {
    puts(query);
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://dict-cli.herokuapp.com/graphql");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/graphql");
        char *dat = query;
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, dat);

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            strcpy(response, curl_easy_strerror(res));
        else {
            curl_easy_cleanup(curl);
            return false;
        }
    } else
        return false;
    return true;
}