#ifndef TEMP_API_H
#define TEMP_API_H

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureData;

typedef struct {
    TemperatureData *data; // Динамический массив
    int size;              // Текущее количество элементов
    int capacity;          // Вместимость массива
} TempStorage;

// Инициализация/освобождение
void init_storage(TempStorage *storage, int initial_capacity);
void free_storage(TempStorage *storage);

// Основные функции
int load_from_file(const char *filename, TempStorage *storage);
void print_data(const TempStorage *storage);
void add_record(TempStorage *storage);
void delete_record(TempStorage *storage, int index);
void sort_by_date(TempStorage *storage);

// Статистика
void print_month_stats(int month, const TempStorage *storage);
void print_year_stats(const TempStorage *storage);

#endif