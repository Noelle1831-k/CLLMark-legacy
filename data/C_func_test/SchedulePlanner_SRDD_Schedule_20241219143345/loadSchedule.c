void loadSchedule() {
    FILE *file = fopen("schedule.dat", "rb");
    if (!file) return;
    fread(&task_count, sizeof(int), 1, file);
    fread(tasks, sizeof(Task), task_count, file);
    fclose(file);
}