void split(const char *word, char result[][2], int *size) {
    int length = strlen(word);
    for (int i = 0; i < length; ++i) {
        result[i][0] = word[i];
        result[i][1] = '\0';
    }
    *size = length;
}