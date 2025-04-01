#include <stdio.h>

int main() {
    int arr[10];
    int sum = 0;

    // Ввод массива
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Вычисление суммы положительных элементов
    for (int i = 0; i < 10; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }

    // Вывод результата
    printf("%d", sum);
    
    return 0;
}