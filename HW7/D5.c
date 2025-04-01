#include <stdio.h>

void reverse_string(int num) {
    // Если число меньше 2, выводим его
    if (num < 2) {
        printf("%d", num);
        return;
    }
    reverse_string(num / 2); // Рекурсивно обрабатываем старшую часть числа
    printf("%d", num % 2); // Выводим текущий остаток (младший бит)
}

int main() {
    int N;
    scanf("%d", &N);
    reverse_string(N);
    printf("\n");
    return 0;
}