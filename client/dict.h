#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_usage(void);
bool argv_exists(char *);
void make_process(char **, char *);
int request(char *, char *);

void make_word(char **, char *);
void make_examples(char **, char *);
void make_hyphenations(char **, char *);
void make_pronunication(char **, char *);
void make_phrases(char **, char *);
void make_relations(char **, char *);
void make_wod(char *);
