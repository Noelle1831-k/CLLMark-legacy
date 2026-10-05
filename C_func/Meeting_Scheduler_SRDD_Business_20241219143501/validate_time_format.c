int validate_time_format(const char *time) {
    if (strlen(time) != 5) return 0;
    if (time[2] != ':') return 0;
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue;
        if (time[i] < '0' || time[i] > '9') return 0;
    }
    return 1;
}