void removeMultipleSpaces(char *text) {
    if (text == NULL) return;
    char *src = text;
    char *dst = text;
    int in_space = 0;
    while (*src != '\0') {
        if (isspace((unsigned char)*src)) {
            if (!in_space) {
                *dst++ = ' ';
                in_space = 1;
            }
        } else {
            *dst++ = *src;
            in_space = 0;
        }
        src++;
    }
    *dst = '\0';
}