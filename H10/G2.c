#include <stdio.h>
#include <stdlib.h>

void generate_string(int N, char *result) {
    int index = 0; // Индекс для букв (A, B, C, ...)
    int digit_count = 0;  // Счётчик для цифр (2, 4, 6, 8, 2, ...)
    
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            // Чётные позиции (0, 2, 4...) — буквы
            result[i] = 'A' + index;
            index++;
        } else {
            // Нечётные позиции (1, 3, 5...) — цифры
            int digit = 2 * (digit_count % 4 + 1);
            result[i] = digit + '0'; // Преобразуем число в символ
            digit_count++;
        }
    }
    result[N] = '\0'; // Завершаем строку
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (!input || !output) {
        printf("Ошибка открытия файлов!\n");
        return 1;
    }
    
    int N;
    fscanf(input, "%d", &N); // Чтение N из файла
    
    char str[N + 1];         // Буфер для строки
    generate_string(N, str);
    
    fprintf(output, "%s", str); // Запись результата
    
    fclose(input);
    fclose(output);
    return 0;
}