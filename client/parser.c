#include "dict.h"

void make_word(char **argv) {
    char query[1000];
    char response[2048];
    strcpy(query, "query{ ");
    char args[100];
    if (argv[0] == NULL) {
        print_usage();
        exit(0);
    }
    strcat(query, "definitions ");
    strcpy(args, "( word:\"");
    strcat(args, argv[0]);
    strcat(args, "\"");
    int i = 1;
    while (argv[i] != NULL) {
        if (strstr(argv[i], "-l") != NULL) {
            char *r;
            strcat(args, ", limit:");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
        } else if (strstr(argv[i], "-pos") != NULL) {
            char *r;
            strcat(args, ", partOfSpeech:\"");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
            strcat(args, "\"");
        } else if (strstr(argv[i], "-ir") != NULL) {
            strcat(args, ", includeRelated: true");
        } else if (strstr(argv[i], "-sds") != NULL) {
            char *r;
            strcat(args, ", sourceDictionaries: \"");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
            strcat(args, "\"");
        } else if (strstr(argv[i], "-uc") != NULL) {
            strcat(args, ", useCanonical: true");
        } else if (strstr(argv[i], "-it") != NULL) {
            strcat(args, ", includeTags: true");
        } else {
            printf("Unknown command: %s\n", argv[i]);
            break;
        }
        i++;
    }
    strcat(args, ")");
    strcat(query, args);
    strcat(query, "{ partOfSpeech text sequence }} ");
    request(query, response);
    parse_word(response, argv[0]);
}

void make_examples(char **argv) {
    if (argv[0] == NULL) {
        print_usage();
        exit(0);
    }
    char args[100];
    char query[1000];
    char response[2048];
    strcpy(query, "query{ ");
    strcat(query, "examples ");
    strcpy(args, "( word:\"");
    strcat(args, argv[0]);
    strcat(args, "\"");
    int i = 1;
    while (argv[i] != NULL) {
        if (strstr(argv[i], "-l") != NULL) {
            char *r;
            strcat(args, ", limit:");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
        } else if (strstr(argv[i], "id") != NULL) {
            strcat(args, ", includeDuplicates: true");
        } else if (strstr(argv[i], "-uc") != NULL) {
            strcat(args, ", useCanonical: true");
        } else if (strstr(argv[i], "-s") != NULL) {
            char *r;
            strcat(args, ", skip:");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
        } else {
            printf("Unknown command: %s\n", argv[i]);
            break;
        }
        i++;
    }
    strcat(args, ")");
    strcat(query, args);
    strcat(query, "{ text title } ");
    strcat(query, "}");
    request(query, response);
    parse_examples(response, argv[0]);
}

void make_hyphenations(char **argv) {
    if (argv[0] == NULL) {
        print_usage();
        exit(0);
    }
    char query[1000];
    char response[2048];
    char args[100];
    strcpy(query, "query{ ");
    strcat(query, "hyphenations ");
    strcpy(args, "( word:\"");
    strcat(args, argv[0]);
    strcat(args, "\"");
    int i = 1;
    while (argv[i] != NULL) {
        if (strstr(argv[i], "-l") != NULL) {
            char *r;
            strcat(args, ", limit:");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
        } else if (strstr(argv[i], "-uc") != NULL) {
            strcat(args, ", useCanonical: true");
        } else if (strstr(argv[i], "-sd") != NULL) {
            char *r;
            strcat(args, ", sourceDictionary: \"");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
            strcat(args, "\"");
        } else {
            printf("Unknown command: %s\n", argv[i]);
            break;
        }
        i++;
    }
    strcat(args, ")");
    strcat(query, args);
    strcat(query, "{ text type seq } }");
    request(query, response);
    parse_hyphenation(response, argv[0]);
}

void make_pronunciation(char **argv) {
    if (argv[0] == NULL) {
        print_usage();
        exit(0);
    }
    char args[100];
    char query[1000];
    char response[2048];
    strcpy(query, "query{ ");
    strcat(query, "pronunciations ");
    strcpy(args, "( word:\"");
    strcat(args, argv[0]);
    strcat(args, "\"");
    int i = 1;
    while (argv[i] != NULL) {
        if (strstr(argv[i], "-l") != NULL) {
            char *r;
            strcat(args, ", limit:");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
        } else if (strstr(argv[i], "-uc") != NULL) {
            strcat(args, ", useCanonical: true");
        } else if (strstr(argv[i], "-sd") != NULL) {
            char *r;
            strcat(args, ", sourceDictionary: \"");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
            strcat(args, "\"");
        } else if (strstr(argv[i], "-tf") != NULL) {
            char *r;
            strcat(args, ", typeFormat: \"");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
            strcat(args, "\"");
        } else {
            printf("Unknown command: %s\n", argv[i]);
            break;
        }
        i++;
    }
    strcat(args, ")");
    strcat(query, args);
    strcat(query, "{ rawType pronunciation }}");
    request(query, response);
    parse_pronunciation(response, argv[0]);
}
void make_phrases(char **argv) {
    if (argv[0] == NULL) {
        print_usage();
        exit(0);
    }
    char query[1000];
    char response[2048];
    char args[100];
    strcpy(query, "query{ ");
    strcat(query, "phrases ");
    strcpy(args, "( word:\"");
    strcat(args, argv[0]);
    strcat(args, "\"");
    int i = 1;
    while (argv[i] != NULL) {
        if (strstr(argv[i], "-l") != NULL) {
            char *r;
            strcat(args, ", limit:");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
        } else if (strstr(argv[i], "-uc") != NULL) {
            strcat(args, ", useCanonical: true");
        } else if (strstr(argv[i], "-wlmi") != NULL) {
            char *r;
            strcat(args, ", wlmi:");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
        } else {
            printf("Unknown command: %s\n", argv[i]);
            break;
        }
        i++;
    }
    strcat(args, ")");
    strcat(query, args);
    strcat(query, "{ gram1 gram2 }}");
    request(query, response);
    parse_phrases(response, argv[0]);
}

void make_relations(char **argv) {
    if (argv[0] == NULL) {
        print_usage();
        exit(0);
    }
    char query[1000];
    char response[2048];
    char args[100];
    strcpy(query, "query{ ");
    strcat(query, "relatedWords ");
    strcpy(args, "( word:\"");
    strcat(args, argv[0]);
    strcat(args, "\"");
    int i = 1;
    while (argv[i] != NULL) {
        if (strstr(argv[i], "-lrt") != NULL) {
            char *r;
            strcat(args, ", limitPerRelationshipType:");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
        } else if (strstr(argv[i], "-uc") != NULL) {
            strcat(args, ", useCanonical: true");
        } else if (strstr(argv[i], "-rt") != NULL) {
            char *r;
            strcat(args, ", relationshipTypes:");
            r = strchr(argv[i], '=') + 1;
            strcat(args, r);
        } else {
            printf("Unknown command: %s\n", argv[i]);
            break;
        }
        i++;
    }
    strcat(args, ")");
    strcat(query, args);
    strcat(query, "{ relationshipType words }}");
    request(query, response);
    parse_related(response, argv[0]);
}

void make_wod(void) {
    char query[1000];
    char response[2048];
    strcpy(query, "query {");
    strcat(query, "wordOfTheDay { word publishDate }}");
    request(query, response);
    parse_wotd(response);
}

void make_process(char **argv) {
    switch (argv[1][1]) {
        case 'd':
            make_word(argv + 2);
            break;
        case 'e':
            make_examples(argv + 2);
            break;
        case 'h':
            make_hyphenations(argv + 2);
            break;
        case 'o':
            make_pronunciation(argv + 2);
            break;
        case 'p':
            make_phrases(argv + 2);
            break;
        case 'r':
            make_relations(argv + 2);
            break;
        case 'x':
            make_wod();
            break;
    }
}
