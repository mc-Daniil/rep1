#include <stdio.h>
#include <string.h>

int main(void) {
    char input[64];
    const char secret[] = "flag{sup3r_S3CR3T_F1AG}";
    printf("Enter password: ");
    if (scanf("%23s", input) != 1) {
        puts("Input error");
        return 1;
    }

    if (strcmp(input, secret) == 0) {
        puts("Correct! :)");
    } else {
        puts("Wrong password :(");
    }

    return 0;
}
