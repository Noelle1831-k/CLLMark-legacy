void log_network_activity(const char *activity) {
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0; 
    printf("Logging activity at %s: %s\n", timestamp, activity);
}