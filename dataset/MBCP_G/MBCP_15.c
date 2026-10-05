char** splitLowerstring(const char* text, int* resultSize) {
    int count = 0, i = 0, j = 0;
    char** result = NULL;
    for (i = 0; text[i] != '\0'; ++i) {
        if (islower(text[i])) {
            count++;
            result = realloc(result, count * sizeof(char*));
            result[count - 1] = (char*)malloc(2 * sizeof(char));
            result[count - 1][0] = text[i];
            result[count - 1][1] = '\0';
        }
    }
    *resultSize = count;
    return result;
}
