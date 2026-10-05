void concatenateStrings(char **testTup1, char **testTup2, char **result, int size) {
    for (int i = 0; i < size; i++) {
        strcpy(result[i], testTup1[i]);
        strcat(result[i], testTup2[i]);
    }
}