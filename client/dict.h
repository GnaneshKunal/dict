#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_usage(void);
bool argv_exists(char *);
char *parser(char *, char *, char *, int, ...);

typedef struct wordDefinition {
    int partOfSpeech;
    int text;
    int sequence;
} wordDefinition;
