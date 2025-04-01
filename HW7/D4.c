#include <stdio.h>

void print_num(int num) {
    if (num < 10) {
        printf("%d", num);  //Одна цифра
    } else {
        print_num(num / 10); // Рекурсивно обрабатываем старшие цифры
        printf(" %d", num % 10); // Печатаем текущую цифру с пробелом
    }
}

int main() {
    int N;
    scanf("%d", &N);
    print_num(N);
    printf("\n"); 
    
    return 0;
}