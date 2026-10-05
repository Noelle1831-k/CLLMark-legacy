#define MAX_WORDS 100
#define MAX_WORD_LENGTH 100
void splitUpperstring(const char *text, char result[MAX_WORDS][MAX_WORD_LENGTH], int *count) {
    *count = 0;
    char currentWord[MAX_WORD_LENGTH] = {0};
    int index = 0, wordIndex = 0;
    while (*text) {
        if (isupper(*text) && index > 0) {
            currentWord[index] = '\0';
            strcpy(result[wordIndex++], currentWord);
            index = 0;
        }
        currentWord[index++] = *text;
        text++;
    }
    if (index > 0) {
        currentWord[index] = '\0';
        strcpy(result[wordIndex++], currentWord);
    }
    *count = wordIndex;
}