char* removeChar(char* str, char ch) {
    int i, j = 0;
    int len = strlen(str);
    char* result = (char*)malloc(len + 1);
    for (i = 0; i < len; i++) {
        if (str[i] != ch) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    return result;
}