int validateDate(const char *date) {
    if (strlen(date) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if ((i == 4 || i == 7) && date[i] != '-') return 0;
        if ((i != 4 && i != 7) && !isdigit(date[i])) return 0;
    }
    return 1;
}