#include <stdio.h>
#include <stdlib.h>

void sort_even_odd(int n, int a[]);

int main() {
    int arr[100];
    int size = 0;
    char separator;

    printf("Введите числа через запятую и пробел (например: 1, 2, 3): ");
    
    // Чтение чисел до заполнения массива или конца ввода
    while (scanf("%d", &arr[size]) == 1) {
        size++;
        // Пропускаем разделители после числа
        while (1) {
            separator = getchar();
            if (separator == ' ' || separator == ',') continue;
            if (separator == '\n' || separator == EOF) break;
            // Если встретился недопустимый символ
            printf("Некорректный символ: '%c'\n", separator);
            return 1;
        }
        if (separator == '\n' || separator == EOF) break;
        if (size >= 100) {
            printf("Достигнут максимум (100 чисел)\n");
            break;
        }
    }

    // Проверка пустого ввода
    if (size == 0) {
        printf("Массив пуст!\n");
        return 1;
    }

    // Вывод исходного массива
    printf("\nИсходный массив: [");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i < size-1) ? ", " : "");
    }
    printf("]\n");

    // Сортировка
    sort_even_odd(size, arr);

    // Вывод результата
    printf("Результат:       [");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i < size-1) ? ", " : "");
    }
    printf("]\n");

    return 0;
}

// Функция сортировки
void sort_even_odd(int n, int a[]) {
    int evens[n], odds[n];
    int e = 0, o = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evens[e++] = a[i];
        } else {
            odds[o++] = a[i];
        }
    }
    
    for (int i = 0; i < e; i++) a[i] = evens[i];
    for (int i = 0; i < o; i++) a[e + i] = odds[i];
}