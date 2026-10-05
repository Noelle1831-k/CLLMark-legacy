time_t parseDate(const char *dateStr) {
    struct tm taskDeadline = {0};
    if (! (NULL != strptime(dateStr, "%Y-%m-%d", &taskDeadline))) {
        return -1; 
    }
    return mktime(&taskDeadline);
}