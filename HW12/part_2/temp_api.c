#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int load_from_file(const char *filename, TemperatureData *data) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }

    char line[100];
    int counter = 0;
    
    while (fgets(line, sizeof(line), fp) && counter < MAX_ENTRIES) {
        if (sscanf(line, "%d;%d;%d;%d;%d;%d",
                   &data[counter].year,
                   &data[counter].month,
                   &data[counter].day,
                   &data[counter].hour,
                   &data[counter].minute,
                   &data[counter].temperature) == 6) {
            counter++;
        }
    }
    
    fclose(fp);
    return counter;
}

void print_data(const TemperatureData *data, int size) {
    for (int i = 0; i < size; i++) {
        printf("%04d-%02d-%02d %02d:%02d %dC\n",
               data[i].year,
               data[i].month,
               data[i].day,
               data[i].hour,
               data[i].minute,
               data[i].temperature);
    }
}

void add_record(TemperatureData *data, int *size) {
    if (*size >= MAX_ENTRIES) return;
    
    TemperatureData new;
    printf("Введите данные (год месяц день час минута температура): ");
    scanf("%d %d %d %d %d %d", 
          &new.year, &new.month, &new.day,
          &new.hour, &new.minute, &new.temperature);
    
    data[(*size)++] = new;
}

void delete_record(TemperatureData *data, int *size, int index) {
    if (index < 0 || index >= *size) return;
    
    for (int i = index; i < *size - 1; i++)
        data[i] = data[i + 1];
    
    (*size)--;
}

int compare_dates(const void *a, const void *b) {
    TemperatureData *ta = (TemperatureData*)a;
    TemperatureData *tb = (TemperatureData*)b;
    
    if (ta->year != tb->year) return ta->year - tb->year;
    if (ta->month != tb->month) return ta->month - tb->month;
    if (ta->day != tb->day) return ta->day - tb->day;
    if (ta->hour != tb->hour) return ta->hour - tb->hour;
    return ta->minute - tb->minute;
}

void sort_by_date(TemperatureData *data, int size) {
    qsort(data, size, sizeof(TemperatureData), compare_dates);
}

void print_month_stats(int month, TemperatureData *data, int size) {
    int sum = 0, count = 0;
    int min = INT_MAX, max = INT_MIN;
    
    for (int i = 0; i < size; i++) {
        if (data[i].month == month) {
            sum += data[i].temperature;
            count++;
            if (data[i].temperature < min) min = data[i].temperature;
            if (data[i].temperature > max) max = data[i].temperature;
        }
    }
    
    printf("Статистика за месяц %d:\n", month);
    printf("Средняя: %.2fC\n", count ? (float)sum/count : 0);
    printf("Минимальная: %dC\n", min != INT_MAX ? min : 0);
    printf("Максимальная: %dC\n\n", max != INT_MIN ? max : 0);
}

void print_year_stats(TemperatureData *data, int size) {
    int sum = 0, min = INT_MAX, max = INT_MIN;
    
    for (int i = 0; i < size; i++) {
        sum += data[i].temperature;
        if (data[i].temperature < min) min = data[i].temperature;
        if (data[i].temperature > max) max = data[i].temperature;
    }
    
    printf("Годовая статистика:\n");
    printf("Средняя: %.2fC\n", size ? (float)sum/size : 0);
    printf("Минимальная: %dC\n", min != INT_MAX ? min : 0);
    printf("Максимальная: %dC\n\n", max != INT_MIN ? max : 0);
}