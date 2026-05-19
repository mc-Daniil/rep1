// gcc -O0 -fno-stack-protector -z execstack -no-pie -o task task.c
// echo 0 | sudo tee /proc/sys/kernel/randomize_va_space (2)

#include <stdio.h>
#include <unistd.h>

void rop() {
  asm("pop %rdi\n\t"
      "ret");
}

void func() {
  char buffer[32];
  read(0, buffer, 128);
}

int main() {
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  puts("Hello dude!");
  func();
}
