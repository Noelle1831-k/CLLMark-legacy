void logError(const char *message) {
    FILE *file = fopen("error_log.txt", "a");
    if (file) {
        fprintf(file, "Error: %s\n", message);
        fclose(file);
    }
}