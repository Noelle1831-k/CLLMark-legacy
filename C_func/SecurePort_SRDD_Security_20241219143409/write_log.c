void write_log(char *message) {
    pthread_mutex_lock(&file_lock);
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        perror("Error opening log file");
        pthread_mutex_unlock(&file_lock);
        exit(EXIT_FAILURE);
    }
    char *timestamp = get_timestamp();
    fprintf(log_file, "[%s] %s\n", timestamp, message);
    fclose(log_file);
    free(timestamp);
    pthread_mutex_unlock(&file_lock);
}