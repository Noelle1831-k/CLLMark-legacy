double calculateTimeDifference(const char* deadline) {
    struct tm tm;
    strptime(deadline, "%Y-%m-%d", &tm);
    time_t deadlineTime = mktime(&tm), currentTime = getCurrentTime();

    return difftime(deadlineTime, currentTime) / (60 * 60 * 24);
}