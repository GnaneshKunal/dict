#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_usage(void);
bool argv_exists(char *);
char *parser(char *, char *, char *, int, ...);

typedef struct ar_options {
    const char *argv_name;
    const char *argv_value;
} ar_options;

extern ar_options limit;
extern ar_options partOfSpeech;
extern ar_options includeRelated;
extern ar_options sourceDictionaries;
extern ar_options useCanonical;
extern ar_options includeTags;
extern ar_options includeDuplicates;
extern ar_options skip;
extern ar_options sourceDictionary;
extern ar_options wlmi;
extern ar_options typeFormat;
extern ar_options relationshipTypes;
extern ar_options limitPerRelationshipType;

typedef struct wordDefinition {
    ar_options limit;
    ar_options partOfSpeech;
    ar_options includeRelated;
    ar_options sourceDictionaries;
    ar_options useCanonical;
    ar_options includeTags;
} wordDefinition;

typedef struct wordExample {
    ar_options includeDuplicates;
    ar_options useCanonical;
    ar_options skip;
    ar_options limit;
} wordExample;

typedef struct wordHyphenation {
    ar_options useCanonical;
    ar_options sourceDictionary;
    ar_options limit;
} wordHyphenation;

typedef struct wordPhrase {
    ar_options useCanonical;
    ar_options wlmi;
    ar_options limit;
} wordPhrase;

typedef struct wordPronunciation {
    ar_options useCanonical;
    ar_options limit;
    ar_options sourceDictionary;
    ar_options typeFormat;
} wordPronunciation;

typedef struct wordRelated {
    ar_options useCanonical;
    ar_options relationshipTypes;
    ar_options limitPerRelationshipType;
} wordRelated;
