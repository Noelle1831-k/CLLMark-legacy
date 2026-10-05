bool checkInteger(const char *text) {
    if (*text == '\0') return false;
    while (*text) {
        if (!isdigit(*text)) return false;
        text++;
    }
    return true;
}