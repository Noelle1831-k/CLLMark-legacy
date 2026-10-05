void log_message(const char *message) {
    printf("LOG: %s\n", message);
    FILE *log_file = fopen("threathunter.log", "a");
    if (log_file != NULL) {
        fprintf(log_file, "%s: %s\n", __TIME__, message);
        fclose(log_file);
    }
}