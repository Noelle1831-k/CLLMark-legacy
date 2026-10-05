void log_alert(const char *alert) {
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    *(timestamp + strcspn(timestamp, "\n")) = 0; 
    printf("Logging alert at %s: %s\n", timestamp, alert);
}