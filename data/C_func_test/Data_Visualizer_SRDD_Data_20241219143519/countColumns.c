int countColumns(const char *line) {
    int count = 1;
    for (const char *ptr = line; *ptr; ptr++) {
        if (*ptr == ',') {
            count++;
        }
    }
    return count;
}