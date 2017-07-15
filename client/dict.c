#include "dict.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define METHOD(method) (" " method "(word: \" ")
#define METHOD2(str, method) \
    strcat((str), " ");      \
    strcat((str), (method)); \
    strcat((str), "(word: \" ");

void make(int num, ...) {
    va_list arguments;
    int sum = 0;

    va_start(arguments, num);
    for (int x = 0; x < num; x++) {
        sum++;
        puts(va_arg(arguments, char *));
    }
    va_end(arguments);
}

void spark(char *str, char *method, char *word) {
    strcat(str, word);
    strcat(str, method);
    puts(str);
}

int main(int argc, char **argv) {
    // puts("Hello, world");
    // char *options[20] = argv[2];
    // int len = 3;
    // for (int i = 0; i < len; i++)
    //     puts(options[i]);
    // return 0;
    // make(2, "test", "test2");
    // char str[200] = "sdadsa";
    // METHOD2(str, "definitions");
    // puts(str);
    char *str = malloc(sizeof(char) * 200);
    parser(str, argv[1], argv[2], 3, argv[3], argv[4], argv[5]);
    // spark(str, argv[1], argv[2]);
    puts(str);
    return 0;
}