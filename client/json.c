#include "dict.h"
#include <json-c/json.h>

void rem_array(char *word) {
    char o = '"';
    char *k, *m, *n;
    k = strchr(word, o);

    while (k != NULL) {
        *k = '\a';
        k = strchr(k, o);
    }
    m = strchr(word, '[') + 1;
    n = strrchr(word, ']') - 1;
    strncpy(word, m, strlen(m) - strlen(n));
    word[strlen(m) - strlen(n) + 1] = '\0';
    strcpy(word, word);
}

void parse_word(char *data, char *word) {
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
                    if (strcmp(def2, "text") == 0) {
                        strcat(out, ANSI_COLOR_YELLOW "def: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        if (i != len - 1)
                            strcat(out, "\n");
                    } else if (strcmp(def2, "partOfSpeech") == 0) {
                        strcat(out, ANSI_COLOR_BLUE "partOfSpeech: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        if (i != len)
                            strcat(out, "\n");
                    }
                }
            }
        }
    }
    puts(out);
}

void parse_examples(char *data, char *word) {
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
}

void parse_related(char *data, char *word) {

    struct json_object *obj;
    obj = json_tokener_parse(data);
    char out[4096];
    strcpy(out, ANSI_COLOR_GREEN "Related Words: " ANSI_COLOR_RESET);
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
                    if (strcmp(def2, "relationshipType") == 0) {
                        strcat(out, ANSI_COLOR_YELLOW "relationship: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        strcat(out, "\n");
                    } else if (strcmp(def2, "words") == 0) {
                        strcat(out, ANSI_COLOR_BLUE "words: " ANSI_COLOR_RESET);
                        char words[100];
                        strcpy(words, json_object_get_string(val3));
                        rem_array(words);
                        strcat(out, words);
                        if (i != len - 1)
                            strcat(out, "\n");
                    }
                }
            }
        }
    }
    puts(out);
}

void parse_pronunciation(char *data, char *word) {
    struct json_object *obj;
    obj = json_tokener_parse(data);
    char out[4096];
    strcpy(out, ANSI_COLOR_GREEN "Pronunciation: " ANSI_COLOR_RESET);
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
                    if (strcmp(def2, "rawType") == 0) {
                        strcat(out, ANSI_COLOR_YELLOW "Type: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        strcat(out, "\n");
                    } else if (strcmp(def2, "pronunciation") == 0) {
                        strcat(out, ANSI_COLOR_BLUE "pronunciation: " ANSI_COLOR_RESET);
                        strcat(out, json_object_get_string(val3));
                        if (i != len - 1)
                            strcat(out, "\n");
                    }
                }
            }
        }
    }
    puts(out);
}

void parse_hyphenation(char *data, char *word) {
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
            strcat(out, ANSI_COLOR_YELLOW "Hyphenation: " ANSI_COLOR_RESET);
            for (i = 0; i < len; i++) {
                arr = json_object_array_get_idx(val2, i);
                json_object_object_foreach(arr, def2, val3) {
                    if (strcmp(def2, "text") == 0) {
                        strcat(out, json_object_get_string(val3));
                        if ((len - i) != len - 1)
                            strcat(out, "-");
                    }
                }
            }
        }
    }
    puts(out);
}

void parse_phrases(char *data, char *word) {
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
                    if (strcmp(def2, "gram1") == 0) {
                        sprintf(out + strlen(out), ANSI_COLOR_YELLOW "Phrase %d: " ANSI_COLOR_RESET, i + 1);
                        strcat(out, json_object_get_string(val3));
                        strcat(out, " ");
                    } else if (strcmp(def2, "gram2") == 0) {
                        strcat(out, json_object_get_string(val3));
                        if (i != len - 1)
                            strcat(out, "\n");
                    }
                }
            }
        }
    }
    puts(out);
}

void parse_wotd(char *data) {
    struct json_object *obj;
    obj = json_tokener_parse(data);
    char out[4096], word[15], temp[15], query[25], response[200];
    json_object_object_foreach(obj, key, val) {
        struct json_object *data = val;
        json_object_object_foreach(val, def, val2) {
            json_object_object_foreach(val2, def2, val3) {
                if (strcmp(def2, "word") == 0) {
                    strcat(out, ANSI_COLOR_YELLOW "Word of the day: " ANSI_COLOR_RESET);
                    strcat(out, json_object_get_string(val3));
                    strcpy(word, json_object_get_string(val3));
                    word[strlen(word)] = '\0';
                    strcat(out, "\n");
                } else if (strcmp(def2, "publishDate") == 0) {
                    strcat(out, ANSI_COLOR_BLUE "Date: " ANSI_COLOR_RESET);
                    strcat(out, json_object_get_string(val3));
                }
            }
        }
    }
    strcat(query, "{ definitions(word: \"");
    strcat(query, word);
    strcat(query, "\", limit: 2){ text }}");
    puts(out);
    request(query, response);
    parse_word(response, word);
}