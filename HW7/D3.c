#include <stdio.h>

void print_reverse(int n) {
    if (n == 0) {
        printf("0"); // Отдельно обрабатываем ноль
        return;
    }
    // Функция для рекурсии
    void rec(int x) {
        if (x == 0) return;
        printf(" %d", x % 10); // Пробел перед цифрой
        rec(x / 10);
    }
    
    // Печатаем первую цифру без пробела
    printf("%d", n % 10);
    // Рекурсивно обрабатываем оставшиеся цифры
    rec(n / 10);
}

int main() {
    int N;
    scanf("%d", &N);
    print_reverse(N);
    printf("\n");
    
    return 0;
}