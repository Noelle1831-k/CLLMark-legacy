void logActivity(const char *message) {
    FILE *logFile = fopen("activity.log", "a");
    if (logFile == NULL) {
        printf("Error: Unable to open log file.\n");
        return;
    }
    time_t now;
    time(&now);
    fprintf(logFile, "%s - %s\n", ctime(&now), message);
    fclose(logFile);
    printf("Activity logged: %s\n", message);
}