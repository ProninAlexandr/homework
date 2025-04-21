#include "temp_api.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_from_file(const char *filename, TemperatureData *data) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Ошибка открытия файла");
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

void print_all_data(const TemperatureData *data, int size) {
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

// Закомментированные заглушки
/*
float calculateMonthlyAverage(int month, int year, TemperatureData *data, int dataSize) {
    return 0.0f; // Заглушка среднемесячный
}
и другие функции, заглушки
*/