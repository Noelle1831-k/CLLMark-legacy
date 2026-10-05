void log_error(const char *message) {
    FILE *file = fopen("error.log", "a");
    if (!file) {
        fprintf(stderr, "Failed to log error: %s\n", message);
        return;
    }
    fprintf(file, "Error: %s\n", message);
    fclose(file);
}