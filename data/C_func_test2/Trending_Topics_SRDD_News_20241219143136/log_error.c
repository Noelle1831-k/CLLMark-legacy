void log_error(char* message) {
    time_t now;
    time(&now);
    char* formatted_time = format_date(now);
    printf("Error at %s: %s\n", formatted_time, message);
    free(formatted_time);
}