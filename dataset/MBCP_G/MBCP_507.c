void removeWords(char *words[], int wordsCount, char *remove[], int removeCount, char *output[], int *outputCount) {
    int outIdx = 0;
    for (int i = 0; i < wordsCount; i++) {
        int shouldRemove = 0;
        for (int j = 0; j < removeCount; j++) {
            if (strcmp(words[i], remove[j]) == 0) {
                shouldRemove = 1;
                break;
            }
        }
        if (!shouldRemove) {
            output[outIdx++] = words[i];
        }
    }
    *outputCount = outIdx;
}
