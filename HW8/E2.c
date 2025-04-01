#include <stdio.h>

#define SIZE 5 // Размер массива

int main() {
    int arr[SIZE];
    int min;

    // Ввод элементов массива
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Инициализация минимума первым элементом
    min = arr[0];

    // Поиск минимального элемента
    for(int i = 1; i < SIZE; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Вывод результата
    printf(" %d\n", min);

    return 0;
}