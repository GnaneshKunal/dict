#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "dict.h"
#include <curl/curl.h>
#include <json-c/json.h>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

int main(int argc, char **argv) {
    CURL *curl_handle;
    static const char *headerfilename = "head.out";
    FILE *headerfile;
    static const char *bodyfilename = "body.json";
    FILE *bodyfile;
    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* set URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, "http://localhost:8080/graphql");

    /* no progress meter please */
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);

    /* send all data to this function  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);

    /* open the header file */
    headerfile = fopen(headerfilename, "wb");
    if (!headerfile) {
        curl_easy_cleanup(curl_handle);
        return -1;
    }

    /* open the body file */
    bodyfile = fopen(bodyfilename, "wb");
    if (!bodyfile) {
        curl_easy_cleanup(curl_handle);
        fclose(headerfile);
        return -1;
    }

    /* we want the headers be written to this file handle */
    curl_easy_setopt(curl_handle, CURLOPT_HEADERDATA, headerfile);

    /*--*/

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/graphql");


    // char *dat = "{ word(word:\"simulate\") { definitions { partOfSpeech text sequence }} }";
    char *str = malloc(sizeof(char) * 200);
    parser(str, argv[1], argv[2], 3, argv[3], argv[4], argv[5]);
    puts(str);
    char *dat = str;
    // puts(dat);

    curl_easy_setopt(curl_handle, CURLOPT_POSTFIELDS, dat);

    curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headers);


    /*---*/

    /* we want the body be written to this file handle instead of stdout */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, bodyfile);

    /* get it! */
    curl_easy_perform(curl_handle);

    /* close the header file */
    fclose(headerfile);

    /* close the body file */
    fclose(bodyfile);

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    struct json_object *jobj;
    const char *question = "Mum, clouds hide alien spaceships don't they ?";
    const char *answer = "Of course not! (\"sigh\")";
    int i;
    struct {
        int flag;
        const char *flag_str;
    } json_flags[] = {{JSON_C_TO_STRING_PLAIN, "JSON_C_TO_STRING_PLAIN"},
                      {JSON_C_TO_STRING_SPACED, "JSON_C_TO_STRING_SPACED"},
                      {JSON_C_TO_STRING_PRETTY, "JSON_C_TO_STRING_PRETTY"},
                      {JSON_C_TO_STRING_NOZERO, "JSON_C_TO_STRING_NOZERO"},
                      {JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY,
                       "JSON_C_TO_STRING_SPACED | JSON_C_TO_STRING_PRETTY"},
                      {-1, NULL}}; // Create an anonymous struct, instanciate an array and fill it

    printf("Using printf(): \"%s\", \"%s\"\n\n", question, answer);
    printf("Using json_object_to_json_string_ext():\n");

    /*
     * The following create an object and add the question and answer to it.
     */
    jobj = json_object_new_object();
    json_object_object_add(jobj, "question", json_object_new_string(question));
    json_object_object_add(jobj, "answer", json_object_new_string(answer));

    for (i = 0; json_flags[i].flag_str != NULL; i++) {
        printf("\nFlag %s:\n---\n", json_flags[i].flag_str);
        printf("%s\n---\n", json_object_to_json_string_ext(jobj, json_flags[i].flag));
    }

    json_object_put(jobj); // Delete the json object

    return 0;
}
