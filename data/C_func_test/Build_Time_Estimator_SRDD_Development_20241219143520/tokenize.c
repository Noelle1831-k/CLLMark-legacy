char *tokenize(char *str, const char *delim) {
    static char *next;
    if (str) next = str;
    if (!next) return NULL;
    char *result = next;
    while (*next) {
        if (strchr(delim, *next)) {
            *next = '\0';
            next++;
            return result;
        }
        next++;
    }
    next = NULL;
    return result;
}