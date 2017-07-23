#include "dict.h"
#include <json-c/json.h>

char jsonstr[] = "{  \"data\": {    \"definitions\": [      {        \"text\": \"To laugh with "
                 "repeated short, spasmodic sounds.\",        \"partOfSpeech\": "
                 "\"verb-intransitive\"      },      {        \"text\": \"To utter while "
                 "giggling.\",        \"partOfSpeech\": \"verb-transitive\"      },      {        "
                 "\"text\": \"A short, spasmodic laugh.\",        \"partOfSpeech\": \"noun\"      "
                 "}    ]  }}";

char json2[] =
"{  \"data\": {    \"examples\": [      {        \"text\": \"MC: * giggle, giggle* Sooooo tall me, "
"are you going to have any of your clothes, like, inspired by India?\",        \"title\": \"The "
"Compulsive Confessor\"      },      {        \"text\": \"* I always knew "
"I was her favorite ... giggle giggle giggle*\",        \"title\": \"Knowledge is "
"Power\"      },      {        \"text\": \"We both started to giggle and I can tell you "
"my daughter will not be toilet papering the neighbors. (now my nose was running. * "
"giggle*)\",        \"title\": \"Spiritually Unequal Marriage\"      },      {        "
"\"text\": \"I guess seeing that smile or hearing a giggle is what keeps us going.\",    "
"    \"title\": \"Hello, Goodbye | Her Bad Mother\"      },      {        \"text\": \"A "
"good giggle is a great way to start the day off.\",        \"title\": \"FRANKENSTEIN'S "
"MONSTERS • by John Wiswell\"      }]}}";

char json_relate[] =
"{  \"data\": {    \"relatedWords\": [      {        \"relationshipType\": \"verb-form\",        "
"\"words\": [          \"giggled\",          \"giggles\",          \"giggling\"        ]      },   "
"   {        \"relationshipType\": \"hypernym\",        \"words\": [          \"laugh\",          "
"\"express mirth\",          \"express joy\",          \"laughter\"        ]      },      {        "
"\"relationshipType\": \"form\",        \"words\": [          \"giggled\",          \"giggling\",  "
"        \"giggly\"        ]      },      {        \"relationshipType\": \"synonym\",        "
"\"words\": [          \"laugh\"        ]      },      {        \"relationshipType\": \"rhyme\",   "
"     \"words\": [          \"jiggle\",          \"riggle\",          \"squiggle\",          "
"\"wiggle\",          \"wriggle\"        ]      },      {        \"relationshipType\": "
"\"same-context\",        \"words\": [          \"chuckle\",          \"gasp\",          "
"\"squeal\",          \"titter\",          \"cackle\",          \"sob\",          \"guffaw\",      "
"    \"smirk\",          \"snort\",          \"whimper\"        ]      }    ]  }}";
int parse_word(char *data, char *word) {
    struct json_object *obj;
    obj = json_tokener_parse(data);
    char out[4096];
    strcpy(out, ANSI_COLOR_GREEN "Word: " ANSI_COLOR_RESET);
    strcat(out, word);
    strcat(out, "\n");
    json_object_object_foreach(obj, key, val) {
        struct json_object *data = val;
        json_object_object_foreach(val, def, val2) {
            struct json_object *arr;
            int i, len = json_object_array_length(val2);
            for (i = 0; i < len; i++) {
                arr = json_object_array_get_idx(val2, i);
                json_object_object_foreach(arr, def2, val3) {
                    // printf("key = %s value = %s\n", def2, json_object_get_string(val3));
                    if (strcmp(def2, "text") == 0) {
                        strcat(out, ANSI_COLOR_YELLOW "def: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        strcat(out, "\t");
                    } else if (strcmp(def2, "partOfSpeech") == 0) {
                        strcat(out, ANSI_COLOR_BLUE "partOfSpeech: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        if (i != len - 1)
                            strcat(out, "\n");
                    }
                }
            }
        }
    }
    puts(out);
    // printf(ANSI_COLOR_YELLOW "%s" ANSI_COLOR_RESET "\n", defs);
    // printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET "\n", defs);
    // printf(ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET "\n", defs);
    // printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "\n", defs);
    // printf(ANSI_COLOR_CYAN "%s" ANSI_COLOR_RESET "\n", defs);
    return 0;
}

int parse_examples(char *data, char *word) {
    struct json_object *obj;
    obj = json_tokener_parse(data);
    char out[4096];
    strcpy(out, ANSI_COLOR_GREEN "Examples: " ANSI_COLOR_RESET);
    strcat(out, word);
    strcat(out, "\n");
    json_object_object_foreach(obj, key, val) {
        struct json_object *data = val;
        json_object_object_foreach(val, def, val2) {
            struct json_object *arr;
            int i, len = json_object_array_length(val2);
            for (i = 0; i < len; i++) {
                arr = json_object_array_get_idx(val2, i);
                json_object_object_foreach(arr, def2, val3) {
                    if (strcmp(def2, "text") == 0) {
                        strcat(out, ANSI_COLOR_YELLOW "example: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        strcat(out, "\n");
                    } else if (strcmp(def2, "title") == 0) {
                        strcat(out, ANSI_COLOR_BLUE "title: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        if (i != len - 1)
                            strcat(out, "\n");
                    }
                }
            }
        }
    }
    puts(out);
    return 0;
}

int main(int argc, char **argv) {
    struct json_object *obj;
    obj = json_tokener_parse(json_relate);
    char out[4096];
    strcpy(out, ANSI_COLOR_GREEN "Related Words: " ANSI_COLOR_RESET);
    strcat(out, argv[1]);
    strcat(out, "\n");
    json_object_object_foreach(obj, key, val) {
        struct json_object *data = val;
        json_object_object_foreach(val, def, val2) {
            struct json_object *arr;
            int i, len = json_object_array_length(val2);
            for (i = 0; i < len; i++) {
                arr = json_object_array_get_idx(val2, i);
                json_object_object_foreach(arr, def2, val3) {
                    printf("key = %s value = %s\n", def2, json_object_get_string(val3));
                    if (strcmp(def2, "relationshipType") == 0) {
                        strcat(out, ANSI_COLOR_YELLOW "example: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        strcat(out, "\n");
                    } else if (strcmp(def2, "title") == 0) {
                        strcat(out, ANSI_COLOR_BLUE "title: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        if (i != len - 1)
                            strcat(out, "\n");
                    }
                }
            }
        }
    }
    puts(out);
    return 0;
}
