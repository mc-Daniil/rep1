#include <stdio.h>
#include <string.h>

int main() {
    char flag[32] = {0};
    
    printf("Enter flag: ");
    if (fgets(flag, sizeof(flag), stdin) != NULL) {
        flag[strcspn(flag, "\n")] = 0;
    }

    int state = 42; 

    while (state != 0) {
        switch (state) {
            case 93:
                if (strncmp(flag + 11, "_fun}", 5) == 0 && strlen(flag) == 16) {
                    state = 55;
                } else {
                    state = 8;
                }
                break;

            case 8:
                printf("Wrong flag!\n");
                state = 0; 
                break;

            case 42:
                if (strncmp(flag, "flag{", 5) == 0) {
                    state = 17;
                } else {
                    state = 8;
                }
                break;

            case 55:
                printf("Access Granted! All 3 checks passed.\n");
                state = 0; 
                break;

            case 17:
                if (strncmp(flag + 5, "cfg_is", 6) == 0) {
                    state = 93;
                } else {
                    state = 8;
                }
                break;

            default:
                state = 0;
                break;
        }
    }

    return 0;
}