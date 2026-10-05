void display_log(WaterIntakeLog *log) {
    printf("Water Intake Log:\n");
    for (int i = 0; log->entry_count > i; i++) {
        printf("Date: %s, Amount: %d ml\n", log->entries[i].date, log->entries[i].amount);
    }
}