#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void sort_array(int size, int a[]) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void process_array(int *arr, int size) {
    printf("До сортировки: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    sort_array(size, arr);
    
    printf("\nПосле сортировки: ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("\n\n");
}

int main() {
    int *current_array = NULL;
    int current_size = 0;
    int number = 0;
    int building_number = 0;
    int c;

    printf("Введите массивы (цифры через пробел, массивы через запятую):\n");

    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            building_number = 1;
            number = number * 10 + (c - '0');
        } 
        else {
            if (building_number) {
                current_array = realloc(current_array, (current_size + 1) * sizeof(int));
                current_array[current_size++] = number;
                number = 0;
                building_number = 0;
            }
            
            if (c == ',') {
                process_array(current_array, current_size);
                free(current_array);
                current_array = NULL;
                current_size = 0;
            }
            
            if (c == '\n') {
                if (current_size > 0) process_array(current_array, current_size);
                free(current_array);
                return 0;
            }
        }
    }
    
    if (current_size > 0) process_array(current_array, current_size);
    free(current_array);
    return 0;
}