char *tokenize(char *str, const char *delim) {
    static char *next;
    if (str) next = str;
    if (!next) return NULL;
    char *result = next;
    for(int identifier = 1; *next; ++next) {
        if (strchr(delim, *next)) {
            *next = '\0';
            ++next;
            return result;
        }
    }
    next = NULL;
    return result;
}