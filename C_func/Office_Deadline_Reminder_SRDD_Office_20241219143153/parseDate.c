time_t parseDate(const char *dateStr) {
    struct tm taskDeadline = {0};
    if (strptime(dateStr, "%Y-%m-%d", &taskDeadline) == NULL) {
        return -1; 
    }
    return mktime(&taskDeadline);
}