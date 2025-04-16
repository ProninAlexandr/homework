#include <stdio.h>
#include <string.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    
    if (!input || !output) {
        printf("Ошибка открытия файлов!\n");
        return 1;
    }
    
    char str[101];
    fgets(str, 101, input);
    str[strcspn(str, "\n")] = '\0'; // Удаляем перенос строки
    
    int length = strlen(str);
    fprintf(output, "%s, %s, %s %d", str, str, str, length);
    
    fclose(input);
    fclose(output);
    return 0;
}