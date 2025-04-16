#include <stdio.h>
#include <string.h>

int main() {
    // Инициализация файлов ввода-вывода
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    if (!input_file || !output_file) return 1;

    // Буфер для приема данных
    char data_buffer[1001];
    fgets(data_buffer, 1001, input_file);
    
    // Проверка длины пакета
    int packet_length = strlen(data_buffer);
    while (packet_length > 0 && (data_buffer[packet_length-1] == '\n' || data_buffer[packet_length-1] == ' ')) 
        data_buffer[--packet_length] = '\0';
    
    if (!packet_length) return 0;
    
    char target_signal = data_buffer[packet_length-1];
    int first_match = 1; // Флаг первого совпадения

    // Сканирование каналов данных
    for (int channel = 0; channel < packet_length-1; channel++) {
        if (data_buffer[channel] == target_signal) {
            // Отправка позиции совпадения в файл
            fprintf(output_file, first_match ? "%d" : " %d", channel);
            first_match = 0; // Сброс флага после первого совпадения
        }
    }

    // Завершение работы с периферией
    fclose(input_file);
    fclose(output_file);
    return 0;
}