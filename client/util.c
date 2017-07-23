#include "dict.h"

const char argv_valid[][7] = {"-d", "-e", "-h", "-p", "-o", "-r", "-x"};

void print_usage(void) {
    printf("Usage: dict [options] word [other options]...\n");
    printf("Options:\n");
    printf("\t-d\t: Get word Definition\n");
    printf("\t-e\t: Get word Examples\n");
    printf("\t-h\t: Get word Hyphenation\n");
    printf("\t-p\t: Get word Phrases\n");
    printf("\t-o\t: Get word Pronunciation\n");
    printf("\t-r\t: Get word Relations\n");
    printf("\t-x\t: Get word of the day\n");
}

bool argv_exists(char *str) {
    bool exists = false;
    int i;
    for (i = 0; i < 7; i++)
        if (strcmp(str, argv_valid[i]) == 0) {
            exists = true;
            break;
        }
    return exists;
}
