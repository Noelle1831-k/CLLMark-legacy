int get_intake(WaterIntakeLog *log) {
    int total = 0;
    for (int i = 0; i < log->entry_count; i++) {
        total += log->entries[i].amount;
    }
    return total;
}