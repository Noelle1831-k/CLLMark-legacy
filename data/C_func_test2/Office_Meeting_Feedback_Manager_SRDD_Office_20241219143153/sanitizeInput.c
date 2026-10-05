void sanitizeInput(char *str) {
    char *p = str;
    while (*p) {
        if (*p == ',' || *p == '\n') {
            *p = ' ';
        }
        p++;
    }
}