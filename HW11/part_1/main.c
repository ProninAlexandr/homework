#include <stdio.h>
#include "temp_api.h"
#include <windows.h>

int main() {
    // Установка кодировки консоли (1251 = Windows-1251)
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    TemperatureData data[MAX_ENTRIES];
    int records;
    
    // Загрузка данных из файла
    if ((records = load_from_file("temperatures.csv", data)) <= 0) {
        return 1;
    }
    
    printf("Загружено записей: %d\n\n", records);
    print_all_data(data, records);
    
    // Пример вызова заглушки
    // printf("\nСредняя температура: %.2f", calculateMonthlyAverage(1, 2023, data, records));
    
    return 0;
}