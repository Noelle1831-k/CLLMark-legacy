void oddValuesString(char *str, char *result) {
    int i, j = 0;
    int length = strlen(str);
    for (i = 0; i < length; i += 2) {
        result[j++] = str[i];
    }
    result[j] = '\0';
}