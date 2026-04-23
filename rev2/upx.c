#include <stdio.h>
#include <string.h>

int main() {
    char input[64] = {0};

    printf("Enter flag: ");
    
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "flag{UpX}") == 0) {
            printf("Correct! You unpacked the mystery!\n");
        } else {
            printf("Wrong flag. Keep digging!\n");
        }
    }

    return 0;
}