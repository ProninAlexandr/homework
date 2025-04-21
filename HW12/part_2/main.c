#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "temp_api.h"

void print_help() {
    printf("Использование:\n"
           "temp_app [-f <файл.csv>] [-m <месяц>] [-h]\n\n"
           "Ключи:\n"
           "-h\tПоказать справку\n"
           "-f\tУказать входной CSV-файл (по умолчанию: temperatures.csv)\n"
           "-m\tФильтр по месяцу (1-12)\n");
}

int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    
    char *filename = "temperatures.csv";
    int month = 0;
    int custom_file = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            print_help();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 && i+1 < argc) {
            filename = argv[++i];
            custom_file = 1;
        }
        else if (strcmp(argv[i], "-m") == 0 && i+1 < argc) {
            month = atoi(argv[++i]);
            if (month < 1 || month > 12) {
                printf("Ошибка: месяц должен быть от 1 до 12\n");
                return 1;
            }
        }
    }

    TemperatureData data[MAX_ENTRIES];
    int records = load_from_file(filename, data);

    if (records <= 0) {
        if (custom_file) {
            printf("Внимание: файл '%s' не найден!\n", filename);
            printf("Пробуем файл по умолчанию...\n");
            filename = "temperatures.csv";
            records = load_from_file(filename, data);
        }
        
        if (records <= 0) {
            printf("Ошибка: файл данных '%s' не найден!\n", filename);
            return 1;
        }
    }

    if (month) {
        print_month_stats(month, data, records);
    } else {
        print_year_stats(data, records);
    }

    return 0;
}