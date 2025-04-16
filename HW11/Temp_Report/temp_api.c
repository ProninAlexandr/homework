#include "temp_api.h"
#include <string.h>
#include <limits.h>

#define MIN_YEAR 2000
#define MAX_YEAR 2100
#define BASE_CAPACITY 100

void init_database(TempDatabase* db) {
    db->data = malloc(BASE_CAPACITY * sizeof(TempRecord));
    db->count = 0;
    db->capacity = BASE_CAPACITY;
}

void add_record(TempDatabase* db, TempRecord record) {
    if (db->count >= db->capacity) {
        db->capacity *= 2;
        db->data = realloc(db->data, db->capacity * sizeof(TempRecord));
    }
    db->data[db->count++] = record;
}

static bool is_valid(const TempRecord* r) {
    return (r->year >= MIN_YEAR && r->year <= MAX_YEAR) &&
           (r->month >= 1 && r->month <= 12) &&
           (r->day >= 1 && r->day <= 31) &&
           (r->hour >= 0 && r->hour <= 23) &&
           (r->minute >= 0 && r->minute <= 59) &&
           (r->temp >= -99 && r->temp <= 99);
}

void load_from_csv(TempDatabase* db, const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) return;

    char line[100];
    while (fgets(line, sizeof(line), f)) {
        TempRecord r;
        if (sscanf(line, "%d,%d,%d,%d,%d,%d",
                  &r.year, &r.month, &r.day,
                  &r.hour, &r.minute, &r.temp) == 6) {
            if (is_valid(&r)) add_record(db, r);
        }
    }
    fclose(f);
}

static void calculate_stats(TempDatabase* db, bool (*filter)(const TempRecord*, int, int, int),
                           int y, int m, int d, float* avg, int* min, int* max) {
    int sum = 0, cnt = 0;
    *min = INT_MAX;
    *max = INT_MIN;

    for (int i = 0; i < db->count; i++) {
        if (filter(&db->data[i], y, m, d)) {
            sum += db->data[i].temp;
            cnt++;
            if (db->data[i].temp < *min) *min = db->data[i].temp;
            if (db->data[i].temp > *max) *max = db->data[i].temp;
        }
    }
    *avg = cnt ? (float)sum / cnt : NAN;
}

// Фильтры
static bool year_filter(const TempRecord* r, int y, int m, int d) {
    (void)m; (void)d;
    return r->year == y;
}

static bool month_filter(const TempRecord* r, int y, int m, int d) {
    (void)d;
    return r->year == y && r->month == m;
}

static bool day_filter(const TempRecord* r, int y, int m, int d) {
    return r->year == y && r->month == m && r->day == d;
}

// Отчеты
void print_year_report(TempDatabase* db, int year) {
    float avg;
    int min, max;
    calculate_stats(db, year_filter, year, 0, 0, &avg, &min, &max);
    printf("\n=== Year %d ===\nAverage: %.1f°C\nMin: %d°C\nMax: %d°C\n", year, avg, min, max);
}

void print_month_report(TempDatabase* db, int year, int month) {
    float avg;
    int min, max;
    calculate_stats(db, month_filter, year, month, 0, &avg, &min, &max);
    printf("\n=== %d-%02d ===\nAverage: %.1f°C\nMin: %d°C\nMax: %d°C\n", year, month, avg, min, max);
}

void print_day_report(TempDatabase* db, int year, int month, int day) {
    float avg;
    int min, max;
    calculate_stats(db, day_filter, year, month, day, &avg, &min, &max);
    printf("\n=== %d-%02d-%02d ===\nAverage: %.1f°C\nMin: %d°C\nMax: %d°C\n", year, month, day, avg, min, max);
}

void print_date_range_report(TempDatabase* db, int y1, int m1, int d1, int y2, int m2, int d2) {
    float avg = NAN;
    int min = INT_MAX, max = INT_MIN, sum = 0, cnt = 0;
    
    for (int i = 0; i < db->count; i++) {
        TempRecord* r = &db->data[i];
        if ((r->year > y1 || (r->year == y1 && r->month >= m1 && r->day >= d1)) &&
            (r->year < y2 || (r->year == y2 && r->month <= m2 && r->day <= d2))) {
            sum += r->temp;
            cnt++;
            if (r->temp < min) min = r->temp;
            if (r->temp > max) max = r->temp;
        }
    }
    
    if (cnt > 0) avg = (float)sum / cnt;
    printf("\n=== %04d-%02d-%02d to %04d-%02d-%02d ===\n"
           "Average: %.1f°C\nMin: %d°C\nMax: %d°C\n",
           y1, m1, d1, y2, m2, d2, avg, min, max);
}

void save_to_csv(TempDatabase* db, const char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) return;
    
    for (int i = 0; i < db->count; i++) {
        fprintf(f, "%04d,%02d,%02d,%02d,%02d,%+03d\n",
               db->data[i].year,
               db->data[i].month,
               db->data[i].day,
               db->data[i].hour,
               db->data[i].minute,
               db->data[i].temp);
    }
    fclose(f);
}