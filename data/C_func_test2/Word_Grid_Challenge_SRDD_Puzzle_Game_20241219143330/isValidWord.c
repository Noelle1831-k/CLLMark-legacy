int isValidWord(const char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}