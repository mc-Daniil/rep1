// gcc -o func func.c -fno-stack-protector -no-pie -g
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void hello() {
    puts("Hello");
}

void secret() {
    system("cat flag.txt");
}

struct Data {
    char buf[16];
    void (*fp)();
};

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    
    alarm(60);

    struct Data d = { "", hello };
    
    puts("Input:");
    gets(d.buf);
    
    d.fp();
    
    return 0;
}