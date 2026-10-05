void monitorLogs() {
    printf("Monitoring system logs dynamically...\n");
    FILE *logFile = fopen("/var/log/syslog", "r");
    if (!logFile) {
        perror("Error opening log file");
        return;
    }
    char line[1024];
    while (fgets(line, sizeof(line), logFile)) {
        if (strstr(line, "error") || strstr(line, "failed")) {
            printf("Suspicious log entry detected: %s", line);
        }
    }
    fclose(logFile);
    printf("Log monitoring completed.\n");
}