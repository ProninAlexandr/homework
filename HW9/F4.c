#include <stdio.h>
#include <string.h>

// Объявление функции (прототип)
void print_digit(char s[]);

int main() {
    char input[1000]; // Буфер для ввода строки
    
    // Считываем строку с клавиатуры (включая пробелы)
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);
    
    // Удаляем символ перевода строки '\n' в конце
    input[strcspn(input, "\n")] = '\0'; 
    
    // Вызываем функцию для анализа цифр
    print_digit(input);
    
    return 0;
}

// Реализация функции 
void print_digit(char s[]) {
    int counts[10] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            counts[s[i] - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            printf("%d %d\n", i, counts[i]);
        }
    }
}