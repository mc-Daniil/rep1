// gcc -o int int.c -no-pie -g -fwrapv
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int balance = 2147483600;
    int add;

    puts("=== CENTRAL COUNTING SYSTEM ===");
    puts("Enter increment:");
    scanf("%d", &add);

    balance += add;

    if (balance < 0) {
        puts("SYSTEM ERROR: integer overflow detected");
        system("cat flag.txt");
    } else {
        printf("Current balance: %d\n", balance);
    }

    return 0;
}
