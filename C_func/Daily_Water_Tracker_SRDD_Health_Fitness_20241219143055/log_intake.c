void log_intake(WaterIntakeLog *log, int amount) {
    if (log->entry_count < 365) {
        strcpy(log->entries[log->entry_count].date, current_date());
        log->entries[log->entry_count].amount = amount;
        log->entry_count++;
    }
}