#include <stdio.h>
#include <string.h>
#include <windows.h>

// 1. Фейковая функция (вызывается, если работает отладчик)
void fake_password_check(const char* input) {
    if (strcmp(input, "fake_pass") == 0) {
        printf("[DEBUG MODE] Access Granted? No, this is a honeypot!\n");
    } else {
        printf("Wrong password!\n");
    }
}

// 2. Настоящая функция (вызывается при нормальном запуске)
void password_check(const char* input) {
    unsigned char encrypted_pass[] = {
        82, 88, 85, 83, 79, 70, 81, 85, 5, 107, 100, 85, 71, 103, 73
    };
    int pass_len = sizeof(encrypted_pass);

    if (strlen(input) != pass_len) {
        printf("Wrong password!\n");
        return;
    }

    int is_correct = 1;
    for (int i = 0; i < pass_len; i++) {
        if ((input[i] ^ 52) != encrypted_pass[i]) {
            is_correct = 0;
            break;
        }
    }

    if (is_correct) {
        printf("[+] Access Granted!\n");
    } else {
        printf("Wrong password!\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return 1;
    }

    if (IsDebuggerPresent()) {
        fake_password_check(argv[1]);
    } else {
        password_check(argv[1]);
    }

    return 0;
}