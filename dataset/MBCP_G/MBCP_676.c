void removeExtraChar(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        if (isalnum((unsigned char)*src)) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}