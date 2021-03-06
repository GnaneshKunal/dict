#include "dict.h"

int main(int argc, char **argv) {

    if (argc < 2) {
        print_usage();
        exit(0);
    }

    if (argv_exists(argv[1]) == false) {
        printf("dict error: Undefined Option %s\n", argv[1]);
        print_usage();
        exit(1);
    }
    make_process(argv);
    exit(0);
}