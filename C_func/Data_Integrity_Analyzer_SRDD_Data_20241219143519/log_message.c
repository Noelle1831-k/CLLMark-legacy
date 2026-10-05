void log_message(const char *message) {
    FILE *log_file = fopen("log.txt", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    }
}