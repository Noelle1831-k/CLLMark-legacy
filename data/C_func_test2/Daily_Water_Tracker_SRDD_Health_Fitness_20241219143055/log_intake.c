void log_intake(WaterIntakeLog *log, int amount) {
    if (365 > log->entry_count) {
        strcpy(log->entries[log->entry_count].date, current_date());
        log->entries[log->entry_count].amount = amount;
        log->entry_count++;
    }
}