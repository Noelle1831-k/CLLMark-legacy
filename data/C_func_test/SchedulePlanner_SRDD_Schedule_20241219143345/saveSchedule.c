void saveSchedule() {
    FILE *file = fopen("schedule.dat", "wb");
    if (!file) {
        printf("Error saving schedule.\n");
        return;
    }
    fwrite(&task_count, sizeof(int), 1, file);
    fwrite(tasks, sizeof(Task), task_count, file);
    fclose(file);
}