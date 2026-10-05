char** concatenateElements(char** inputArray, int size) {
    char** result = (char**)malloc((size - 1) * sizeof(char*));
    for (int i = 0; i < size - 1; i++) {
        int len1 = strlen(inputArray[i]);
        int len2 = strlen(inputArray[i + 1]);
        result[i] = (char*)malloc((len1 + len2 + 1) * sizeof(char));
        strcpy(result[i], inputArray[i]);
        strcat(result[i], inputArray[i + 1]);
    }
    return result;
}
