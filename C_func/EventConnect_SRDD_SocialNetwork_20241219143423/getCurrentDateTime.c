void getCurrentDateTime() {
    time_t t;
    struct tm *tm_info;
    char buffer[26];
    time(&t);
    tm_info = localtime(&t);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Current Date and Time: %s\n", buffer);
}