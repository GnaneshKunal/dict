#include "dict.h"

int main(int argc, char **argv) {
    int i;
    if (argc < 2) {
        print_usage();
        exit(0);
    }

    if (argv_exists(argv[1]) == false) {
        printf("dict error: Undefined Option\n");
        print_usage();
        exit(1);
    }
    exit(0);
}