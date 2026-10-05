void capitalWordsSpaces(char *str) {
    size_t length = strlen(str);
    char result[2 * length];
    int index = 0;
    for (size_t i = 0; i < length; i++) {
        if (i > 0 && isupper(str[i])) {
            result[index++] = ' ';
        }
        result[index++] = str[i];
    }
    result[index] = '\0';
    strcpy(str, result);
}