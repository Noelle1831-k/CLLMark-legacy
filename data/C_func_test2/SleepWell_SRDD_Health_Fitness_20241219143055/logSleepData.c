void logSleepData(double hours) {
    FILE *file = fopen("sleep_data.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    time_t now = time(NULL);
    fprintf(file, "Date: %sSleep Duration: %.2f hours\n", ctime(&now), hours);
    fclose(file);
}