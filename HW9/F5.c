#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Объявление функции
int find_max_array(int size, int a[]);

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    char input[4096]; // Буфер для ввода строки

    // Шаг 1: Чтение строки с клавиатуры
    printf("Введите числа через пробел: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Ошибка чтения ввода!\n");
        return 1;
    }

    // Шаг 2: Разбиение строки на числа
    char *token = strtok(input, " \n"); // Разделители: пробел и перевод строки
    while (token != NULL && size < MAX_SIZE) {
        arr[size++] = atoi(token);      // Преобразуем токен в число
        token = strtok(NULL, " \n");    // Следующий токен
    }

    // Шаг 3: Проверка на пустой ввод
    if (size == 0) {
        printf("Ошибка: массив пуст!\n");
        return 1;
    }

    // Шаг 4: Вызов функции и вывод результата
    printf("Максимальный элемент: %d\n", find_max_array(size, arr));

    return 0;
}

// Реализация функции поиска максимума
int find_max_array(int size, int a[]) {
    int max = a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > max) max = a[i];
    }
    return max;
}