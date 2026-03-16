// gcc -o func func.c -fno-stack-protector -no-pie -g
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    struct Data d = { "", hello };
    gets(d.buf);
    d.fp();
    return 0;
}
