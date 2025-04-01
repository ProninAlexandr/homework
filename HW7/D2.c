#include <stdio.h>

int sum_numbers(int n) {
    if (n <= 0) return 0;          // Базовый случай: сумма чисел <= 0 равна 0
    return n + sum_numbers(n - 1); // Рекурсивный шаг: n + сумма предыдущих чисел
}

int main() {
    int N;
    //printf("Введите число N: ");
    scanf("%d", &N);
    printf("%d\n", sum_numbers(N));
    return 0;
}