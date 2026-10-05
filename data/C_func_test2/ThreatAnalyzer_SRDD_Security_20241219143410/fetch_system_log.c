char *fetch_system_log() {
    char *log_entry = (char *)malloc(256);
    if (!log_entry) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(log_entry, "Simulated system log entry...");
    return log_entry;
}