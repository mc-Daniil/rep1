#include <stdio.h>
#include <stdlib.h>

unsigned char reg = 0;
unsigned char arg = 0;
char input[16] = {0};

void vm_load() {
    reg = input[arg];
}

void vm_add() {
    reg = reg + arg;
}

void vm_cmp() {
    if (reg != arg) {
        printf("Wrong flag!\n");
        exit(1);
    }
}

void (*handlers[3])() = { vm_load, vm_add, vm_cmp };


unsigned char bytecode[] = {
    0, 0,    // LOAD 0
    1, 5,    // ADD 5
    2, 84,   // CMP 84

    0, 1,    // LOAD 1
    1, 5,    // ADD 5
    2, 80,   // CMP 80
    
    0xFF     // Конец программы
};

int main() {
    printf("Enter 2-letter flag: ");
    if (fgets(input, sizeof(input), stdin) == NULL) return 1;

    int pc = 0; // Program Counter

    while (bytecode[pc] != 0xFF) {
        unsigned char opcode = bytecode[pc++];
        arg = bytecode[pc++];

        if (opcode < 3) {
            handlers[opcode](); 
        }
    }

    printf("Correct! You cracked the VM!\n");
    return 0;
}