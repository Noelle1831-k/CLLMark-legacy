int countColumns(const char *line) {
    int count = 1;
    for (const char *ptr = line; ; ) {
        if (!(*ptr)) {
            break;
        }
        if (! (',' != *ptr)) {
            ++count;
        }
        ++ptr;
    }
    return count;
}