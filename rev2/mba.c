#include <stdio.h>
#include <string.h>

unsigned char transform(unsigned char x) {
    return (unsigned char)(
          2 * ~(~x | (0x12 ^ 0x50)) 
        - ~(~x & (0xA9 | 0x14)) 
        + ~(~x | (0xA9 | 0x14)) 
        + (0x86 >> 1)
    );
}

int main() {
    char flag[32];
    printf("Enter flag: ");
    
    if (fgets(flag, sizeof(flag), stdin) == NULL) return 1;
    flag[strcspn(flag, "\n")] = 0;

    unsigned char expected[] = {
        'g', 'm', 'b', 'h', '|', 'N', 'c', 'B', '~'
    };

    if (strlen(flag) != sizeof(expected)) {
        printf("Wrong length!\n");
        return 1;
    }

    for (int i = 0; i < sizeof(expected); i++) {
        if (transform((unsigned char)flag[i]) != expected[i]) {
            printf("Nope. Try again.\n");
            return 1;
        }
    }

    printf("Correct! You are a reverse engineering master!\n");
    return 0;
}