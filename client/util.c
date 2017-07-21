#include "dict.h"

const char argv_valid[][6] = {"-d", "-e", "-h", "-p", "-o", "-r"};

ar_options limit = {"-l", "limit"};
ar_options partOfSpeech = {"-pos", "partOfSpeech"};
ar_options includeRelated = {"-ir", "includeRelated"};
ar_options sourceDictionaries = {"-sds", "sourceDictionaries"};
ar_options useCanonical = {"-uc", "useCanonical"};
ar_options includeTags = {"-it", "includeTags"};
ar_options includeDuplicate = {"-id", "includeDuplicates"};
ar_options skip = {"-s", "skip"};
ar_options sourceDictionary = {"-sd", "sourceDictionary"};
ar_options wlmi = {"wl", "wlmi"};
ar_options typeFormat = {"-tf", "typeFormat"};
ar_options relationshipTypes = {"-rt", "relationshipTypes"};
ar_options limitPerRelationshipType = {"-lrt", "limitPerRelationshipType"};

void print_usage(void) {
    printf("Usage: dict [options] word [other options]...\n");
    printf("Options:\n");
    printf("\t-d\t: Get word Definition\n");
    printf("\t-e\t: Get word Examples\n");
    printf("\t-h\t: Get word Hyphenation\n");
    printf("\t-p\t: Get word Phrases\n");
    printf("\t-o\t: Get word Pronunciation\n");
    printf("\t-r\t: Get word Relations\n");
}

bool argv_exists(char *str) {
    bool exists = false;
    int i;
    for (i = 0; i < 6; i++)
        if (strcmp(str, argv_valid[i]) == 0) {
            exists = true;
            break;
        }
    return exists;
}
