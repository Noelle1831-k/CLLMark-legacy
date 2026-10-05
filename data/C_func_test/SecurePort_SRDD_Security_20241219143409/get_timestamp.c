char *get_timestamp() {
    time_t now = time(NULL);
    char *timestamp = malloc(20 * sizeof(char));
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    return timestamp;
}