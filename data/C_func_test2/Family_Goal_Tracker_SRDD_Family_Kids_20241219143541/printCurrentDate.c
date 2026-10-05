void printCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Current Date: %02d-%02d-%04d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}