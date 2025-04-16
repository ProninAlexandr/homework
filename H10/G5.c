#include <stdio.h>
#include <string.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (!input || !output) {
        printf("Ошибка открытия файлов\n");
        return 1;
    }
    
    char str[1001];
    fgets(str, 1001, input); // Чтение строки
    
    for (int i = 0; str[i] != '\0'; i++) {
        // Обработка строчных букв
        if (str[i] == 'a') {
            str[i] = 'b';
        } else if (str[i] == 'b') {
            str[i] = 'a';
        }
        // Обработка заглавных букв
        else if (str[i] == 'A') {
            str[i] = 'B';
        } else if (str[i] == 'B') {
            str[i] = 'A';
        }
    }
    
    fprintf(output, "%s", str); // Запись результата
    
    fclose(input);
    fclose(output);
    return 0;
}