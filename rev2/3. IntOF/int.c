// gcc -o int int.c -no-pie -g -fwrapv
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    alarm(60);

    int balance = 2147483600;
    int add;

    puts("=== CENTRAL COUNTING SYSTEM ===");
    puts("Enter increment:");
    scanf("%d", &add);

    balance += add;

    if (balance < 0) {
        system("cat flag.txt");
    } else {
        printf("Current balance: %d\n", balance);
    }

    return 0;
}