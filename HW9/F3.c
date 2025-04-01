#include <stdio.h>

void print_digits_counts(char *number);

int main() {
    char number[1001]; // Массив для числа (1000 цифр + '\0')
    scanf("%1000s", number); // Чтение числа как строки
    
    print_digits_counts(number); // Вызов функции обработки
    
    return 0;
}

// Реализация функции
void print_digits_counts(char *number) {
    int counts[10] = {0};
    for (int i = 0; number[i] != '\0'; i++) {
        char c = number[i];
        if (c >= '0' && c <= '9') {
            counts[c - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            printf("%d %d\n", i, counts[i]);
        }
    }
}