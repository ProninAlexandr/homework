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

// Функции работы с данными
int load_from_file(const char *filename, TemperatureData *data);
void print_all_data(const TemperatureData *data, int size);

// Закомментированные заглушки отчетов
/*
float calculateMonthlyAverage(int month, int year, TemperatureData *data, int dataSize);
int findMonthlyMin(int month, int year, TemperatureData *data, int dataSize);
int findMonthlyMax(int month, int year, TemperatureData *data, int dataSize);
float calculateYearlyAverage(int year, TemperatureData *data, int dataSize);
int findYearlyMin(int year, TemperatureData *data, int dataSize);
int findYearlyMax(int year, TemperatureData *data, int dataSize);
*/

#endif