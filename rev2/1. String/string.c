// gcc -o string string.c -fno-stack-protector -no-pie
#include <stdio.h>
#include <stdlib.h>

struct Data {
    char name[4];
    char command[16];
} data = { "", "echo Hello" };

int main(void)
{
    puts("Input:");
    gets(data.name); // небезопасно
    printf("You entered: %s\n", data.command);
    system(data.command);
    return 0;
}
