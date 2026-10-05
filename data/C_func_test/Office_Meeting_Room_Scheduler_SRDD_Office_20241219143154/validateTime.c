int validateTime(const char *time) {
    if (strlen(time) != 5) return 0;
    for (int i = 0; i < 5; i++) {
        if (i == 2 && time[i] != ':') return 0;
        if (i != 2 && !isdigit(time[i])) return 0;
    }
    return 1;
}