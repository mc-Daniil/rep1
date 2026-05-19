#include <stdio.h>
#include <string.h>

int main() {
    char pass[4];
    scanf("%s", pass);
    if (!strncmp(pass, "abcd", 4)) {
        puts("OK");
    }
    else {
        puts("NO");
    }
    return 0;
}