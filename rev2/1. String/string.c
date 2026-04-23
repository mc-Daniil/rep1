// gcc -o string string.c -fno-stack-protector -no-pie -g
#include <stdio.h>
#include <stdlib.h>

struct Data {
    char name[4];
    char command[16];
} data = { "", "echo Hello" };

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    puts("Input:");
    gets(data.name); // небезопасно
    printf("You entered: %s\n", data.command);
    system(data.command);
    return 0;
}
