void sendAlert(const char *message) {
    printf("ALERT: %s\n", message);
    FILE *logFile = fopen("alerts.log", "a");
    if (logFile) {
        fprintf(logFile, "ALERT: %s\n", message);
        fclose(logFile);
    }
}