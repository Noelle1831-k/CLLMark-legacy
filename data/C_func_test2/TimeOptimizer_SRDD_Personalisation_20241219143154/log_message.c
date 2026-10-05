void log_message(const char *message) {
    time_t current_time = time(NULL);
    char *timestamp = ctime(&current_time);
    timestamp[strlen(timestamp) - 1] = '\0'; 
    printf("[%s] LOG: %s\n", timestamp, message);
}