void log_event(const char *format, ...) {
    FILE *logfile = fopen("securedetect.log", "a");
    if (logfile == NULL) {
        return;
    }
    va_list args;
    va_start(args, format);
    time_t now = time(NULL);
    fprintf(logfile, "[%s] ", ctime(&now));
    vfprintf(logfile, format, args);
    fprintf(logfile, "\n");
    va_end(args);
    fclose(logfile);
}