int isDateInRange(const char *date, const char *startDate, const char *endDate) {
    return strcmp(date, startDate) >= 0 && strcmp(date, endDate) <= 0;
}