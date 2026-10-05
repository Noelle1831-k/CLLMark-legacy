char** extractRear(char** testTuple, int size) {
    char** result = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        int len = strlen(testTuple[i]);
        result[i] = (char*)malloc(2 * sizeof(char));
        result[i][0] = testTuple[i][len - 1];
        result[i][1] = '\0';
    }
    return result;
}