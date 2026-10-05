void log_event(char *event) {
    pthread_mutex_lock(&log_lock);
    char *timestamp = get_timestamp();
    printf("[%s] %s\n", timestamp, event);
    free(timestamp);
    pthread_mutex_unlock(&log_lock);
}