void viewSleepStatistics() {
    FILE *file = fopen("sleep_data.txt", "r");
    if (file == NULL) {
        printf("No sleep data available.\n");
        return;
    }
    char line[256];
    printf("\nSleep Statistics:\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}