#include <stdio.h>

#define SIZE 5

int main() {
    int numbers[SIZE];
    int sum = 0;
    
    // Ввод массива
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &numbers[i]);
        sum += numbers[i]; // Суммируем элементы
    }
    
    // Вычисление среднего
    float average = (float)sum / SIZE;
    
    // Вывод результата с точностью до трёх знаков
    printf("%.3f\n", average);
    
    return 0;
}