void removeSplchar(char *result, const char *text) {
    int j = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            result[j++] = text[i];
        }
    }
    result[j] = '\0';
}