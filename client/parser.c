#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define METHOD(method) " " method "(word: \" "
#define METHOD(str, method)  \
    strcat((str), " ");      \
    strcat((str), (method)); \
    strcat((str), "(word: \"");

char *parser(char *str, char *method, char *word, int options_length, ...) {
    int i;
    // if (strcmp(method, "mean") != 0) {
    //     puts("options");
    //     return 0;
    // }
    strcat(str, "{");
    if (strcmp(method, "definitions") != 0) {
        puts("something went wrong");
        exit(0);
    }
    METHOD(str, method);
    // strcat(str, " ");
    // strcat(str, method);
    // strcat(str, "(word: \" ");
    // strcat(str, " definitions(word: \"");
    strcat(str, word);
    strcat(str, "\") {");
    //     strcat(str, "text \
// sequence \
// partOfSpeech");
    // for (i = 0; i < options_length; i++) {
    //     strcat(str, options[i]);
    //     strcat(str, " ");
    // }
    va_list options;
    va_start(options, options_length);
    for (int x = 0; x < options_length; x++) {
        strcat(str, (va_arg(options, char *)));
        strcat(str, " ");
    }
    va_end(options);
    strcat(str, "} }");
    return str;
}
