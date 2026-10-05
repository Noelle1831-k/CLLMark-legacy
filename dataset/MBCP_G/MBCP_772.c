char* removeLength(const char* testStr, int k) {
    char* result = malloc(strlen(testStr) + 1);
    char* word;
    char* copy = strdup(testStr);
    int length;
    int pos = 0;
    word = strtok(copy, " ");
    while (word != NULL) {
        length = strlen(word);
        if (length != k) {
            if (pos != 0) {
                result[pos++] = ' ';
            }
            strcpy(result + pos, word);
            pos += length;
        }
        word = strtok(NULL, " ");
    }
    result[pos] = '\0';
    free(copy);
    return result;
}