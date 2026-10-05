void removeWhitespaces(char *text) {
    int i, j = 0;
    int len = strlen(text);
    for (i = 0; i < len; i++) {
        if (!isspace(text[i])) {
            text[j++] = text[i];
        }
    }
    text[j] = '\0';
}