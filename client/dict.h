#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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
