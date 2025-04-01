#include <stdio.h>

void print_numbers(int n) {
    if (n < 1) return; // Если n меньше 1, ничего не делаем
    
    print_numbers(n - 1); // Рекурсивный вызов с уменьшенным значением
    printf("%d ", n);     // Печать текущего числа после возврата из рекурсии
}

int main() {
    int N;
    scanf("%d", &N);
    print_numbers(N);
    printf("\n");
    
    return 0;
}