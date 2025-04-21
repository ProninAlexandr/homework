#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Инициализация хранилища
void init_storage(TempStorage *storage, int initial_capacity) {
    storage->data = malloc(initial_capacity * sizeof(TemperatureData));
    storage->size = 0;
    storage->capacity = initial_capacity;
}

// Освобождение памяти
void free_storage(TempStorage *storage) {
    free(storage->data);
    storage->size = 0;
    storage->capacity = 0;
}

// Увеличение вместимости
static void resize_storage(TempStorage *storage) {
    int new_capacity = storage->capacity * 2;
    TemperatureData *new_data = realloc(storage->data, new_capacity * sizeof(TemperatureData));
    if (new_data) {
        storage->data = new_data;
        storage->capacity = new_capacity;
    }
}

// Загрузка из файла
int load_from_file(const char *filename, TempStorage *storage) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return -1;

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        if (storage->size >= storage->capacity) {
            resize_storage(storage);
        }
        
        TemperatureData *record = &storage->data[storage->size];
        if (sscanf(line, "%d;%d;%d;%d;%d;%d",
                   &record->year,
                   &record->month,
                   &record->day,
                   &record->hour,
                   &record->minute,
                   &record->temperature) == 6) {
            storage->size++;
        }
    }
    
    fclose(fp);
    return storage->size;
}

// Печать данных
void print_data(const TempStorage *storage) {
    for (int i = 0; i < storage->size; i++) {
        printf("%04d-%02d-%02d %02d:%02d %dC\n",
               storage->data[i].year,
               storage->data[i].month,
               storage->data[i].day,
               storage->data[i].hour,
               storage->data[i].minute,
               storage->data[i].temperature);
    }
}

// Добавление записи
void add_record(TempStorage *storage) {
    if (storage->size >= storage->capacity) {
        resize_storage(storage);
    }
    
    TemperatureData *record = &storage->data[storage->size];
    printf("Введите данные (год месяц день час минута температура): ");
    scanf("%d %d %d %d %d %d", 
          &record->year, 
          &record->month,
          &record->day,
          &record->hour,
          &record->minute,
          &record->temperature);
    
    storage->size++;
}

// Удаление записи
void delete_record(TempStorage *storage, int index) {
    if (index < 0 || index >= storage->size) return;
    
    for (int i = index; i < storage->size - 1; i++) {
        storage->data[i] = storage->data[i + 1];
    }
    storage->size--;
}

// Сравнение для сортировки
static int compare_dates(const void *a, const void *b) {
    const TemperatureData *ta = a;
    const TemperatureData *tb = b;
    
    if (ta->year != tb->year) return ta->year - tb->year;
    if (ta->month != tb->month) return ta->month - tb->month;
    if (ta->day != tb->day) return ta->day - tb->day;
    if (ta->hour != tb->hour) return ta->hour - tb->hour;
    return ta->minute - tb->minute;
}

// Сортировка
void sort_by_date(TempStorage *storage) {
    qsort(storage->data, storage->size, sizeof(TemperatureData), compare_dates);
}

// Статистика за месяц
void print_month_stats(int month, const TempStorage *storage) {
    int sum = 0, count = 0;
    int min = INT_MAX, max = INT_MIN;
    
    for (int i = 0; i < storage->size; i++) {
        if (storage->data[i].month == month) {
            sum += storage->data[i].temperature;
            count++;
            if (storage->data[i].temperature < min) min = storage->data[i].temperature;
            if (storage->data[i].temperature > max) max = storage->data[i].temperature;
        }
    }
    
    printf("Статистика за месяц %d:\n", month);
    printf("Средняя: %.2fC\n", count ? (float)sum/count : 0);
    printf("Минимальная: %dC\n", min != INT_MAX ? min : 0);
    printf("Максимальная: %dC\n\n", max != INT_MIN ? max : 0);
}

// Статистика за год
void print_year_stats(const TempStorage *storage) {
    int sum = 0, min = INT_MAX, max = INT_MIN;
    
    for (int i = 0; i < storage->size; i++) {
        sum += storage->data[i].temperature;
        if (storage->data[i].temperature < min) min = storage->data[i].temperature;
        if (storage->data[i].temperature > max) max = storage->data[i].temperature;
    }
    
    printf("Годовая статистика:\n");
    printf("Средняя: %.2fC\n", storage->size ? (float)sum/storage->size : 0);
    printf("Минимальная: %dC\n", min != INT_MAX ? min : 0);
    printf("Максимальная: %dC\n\n", max != INT_MIN ? max : 0);
}