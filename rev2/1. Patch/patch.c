#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        puts("Error");
        return 1;
    }

    if (!strncmp(argv[1], "pass", 4)) {
        puts("Correct!");
    }
    else {
        puts("Wrong!");
    }

    return 0;
}