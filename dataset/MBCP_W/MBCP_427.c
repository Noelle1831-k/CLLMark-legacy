void changeDateFormat(const char* dt, char* result) {
    char *year = (char *)malloc(sizeof(char) * 5);
    strncpy(year, dt, 4);
    year[4] = '\0';
    strncpy(month, dt + 5, 2);
    month[2] = '\0';
    strncpy(day, dt + 8, 2);
    day[2] = '\0';
    sprintf(result, "%s-%s-%s", day, month, year);
}