#include "utils.h"

char* shift(int* argc, char** argv[]) {
    char* arg = *argv[0];
    *argc -= 1;
    *argv += 1;
    return arg;
}