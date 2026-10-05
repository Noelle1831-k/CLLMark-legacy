char *getCurrentDate() {
    static char date[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(date, sizeof(date), "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    return date;
}