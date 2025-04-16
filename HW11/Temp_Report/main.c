#include "temp_api.h"
#include <stdio.h>
#include <time.h>

void show_main_menu() {
    printf("\n=== Temperature Analyzer ===\n");
    printf("1. Add record (Manual)\n2. Add record (Auto)\n3. Reports\n4. Exit\n> ");
}

void show_report_menu() {
    printf("\n=== Reports ===\n");
    printf("1. Year\n2. Month\n3. Day\n4. Date range\n5. Back\n> ");
}

void add_record_manual(TempDatabase* db) {
    TempRecord r;
    printf("\nEnter [YYYY MM DD HH MM TEMP]: ");
    if (scanf("%d %d %d %d %d %d", 
             &r.year, &r.month, &r.day,
             &r.hour, &r.minute, &r.temp) == 6) {
        add_record(db, r);
        printf("Record added!\n");
    }
}

void add_record_auto(TempDatabase* db) {
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    
    TempRecord r = {
        .year = local->tm_year + 1900,
        .month = local->tm_mon + 1,
        .day = local->tm_mday,
        .hour = local->tm_hour,
        .minute = local->tm_min
    };
    
    printf("\nCurrent time: %04d-%02d-%02d %02d:%02d\n", 
          r.year, r.month, r.day, r.hour, r.minute);
    printf("Enter temperature: ");
    
    if (scanf("%d", &r.temp) == 1) {
        add_record(db, r);
        printf("Record added!\n");
    }
}

void handle_reports(TempDatabase* db) { /* ... */ }

int main() {
    TempDatabase db;
    init_database(&db);
    load_from_csv(&db, "data.csv");

    int choice;
    do {
        show_main_menu();
        if (scanf("%d", &choice) != 1) break;
        
        switch(choice) {
            case 1: 
                add_record_manual(&db);
                break;
            case 2:
                add_record_auto(&db);
                break;
            case 3: 
                handle_reports(&db);
                break;
        }
    } while(choice != 4);
    
    save_to_csv(&db, "data.csv");
    return 0;
}