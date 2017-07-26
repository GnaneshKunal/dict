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
    printf("Other options:\n");
    printf(
    "\t-l={n}\t: Limit the result[definitions, examples, hyphenations, phrases pronunciations]\n");
    printf("\t-uc={b}\t:  Use canonical[all]\n");
    printf("\t-pos={s}\t: PartOfSpeech[definitions]\n");
    printf("\t-sds={s}\t: SourceDictionaries[definitions]\n");
    printf("\t-it={b}\t:  Include Tags[definitions]\n");
    printf("\t-id={b}\t:  Include Duplicates[examples]\n");
    printf("\t-s={n}\t:   Skip[examples]\n");
    printf("\t-sd={s}\t:  SourceDictionary[hyphenations, pronunciations]\n");
    printf("\t-tf={s}\t:  Type format[pronunciations]\n");
    printf("\t-wlmi={s}\t:    wlmi[phrases]\n");
    printf("\t-lrt={s}\t: limitPerRelationshipType[relations]\n");
    printf("\t-rt={s}\t: Relationship Types\n");
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
