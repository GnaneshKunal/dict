#include "dict.h"

int main(int argc, char **argv) {
    char *query = malloc(1000 * sizeof(char));
    if (argc < 2) {
        print_usage();
        exit(0);
    }

    if (argv_exists(argv[1]) == false) {
        printf("dict error: Undefined Option %s\n", argv[1]);
        print_usage();
        exit(1);
    }
    make_process(argv, query);
    exit(0);
}