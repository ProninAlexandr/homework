#ifndef TEMP_API_H
#define TEMP_API_H

#define MAX_ENTRIES 1000

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temperature;
} TemperatureData;

// Основные функции
int load_from_file(const char *filename, TemperatureData *data);
void print_data(const TemperatureData *data, int size);
void add_record(TemperatureData *data, int *size);
void delete_record(TemperatureData *data, int *size, int index);
void sort_by_date(TemperatureData *data, int size);

// Функции статистики
void print_month_stats(int month, TemperatureData *data, int size);
void print_year_stats(TemperatureData *data, int size);

#endif