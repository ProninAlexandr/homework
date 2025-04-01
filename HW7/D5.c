#include <stdio.h>

void print_binary(int num) {
    // Базовый случай: если число меньше 2, выводим его
    if (num < 2) {
        printf("%d", num);
        return;
    }
    
    // Рекурсивно обрабатываем старшую часть числа
    print_binary(num / 2);
    // Выводим текущий остаток (младший бит)
    printf("%d", num % 2);
}

int main() {
    int N;
    scanf("%d", &N);
    print_binary(N);
    printf("\n");
    return 0;
}