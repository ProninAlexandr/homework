#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
} TempRecord;

typedef struct {
    TempRecord* data;
    int count;
    int capacity;
} TempDatabase;

// Управление данными
void init_database(TempDatabase* db);
void add_record(TempDatabase* db, TempRecord record);
void save_to_csv(TempDatabase* db, const char* filename);
void load_from_csv(TempDatabase* db, const char* filename);

// Отчеты
void print_year_report(TempDatabase* db, int year);
void print_month_report(TempDatabase* db, int year, int month);
void print_day_report(TempDatabase* db, int year, int month, int day);
void print_date_range_report(TempDatabase* db, int y1, int m1, int d1, int y2, int m2, int d2);

#endif