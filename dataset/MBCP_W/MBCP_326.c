#define MAX_WORD_LEN 100
typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;
char* mostOccurrences(char *testList[], int n) {
    WordCount ;
    WordCount *wordCounts = (WordCount *)malloc(sizeof(WordCount) * MAX_WORD_LEN * 100);
    int totalWords = 0;
    for (int i = 0; i < n; i++) {
        char *str = strdup(testList[i]);
        char *token = strtok(str, " ");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < totalWords; j++) {
                if (strcmp(wordCounts[j].word, token) == 0) {
                    wordCounts[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(wordCounts[totalWords].word, token);
                wordCounts[totalWords].count = 1;
                totalWords++;
            }
            token = strtok(NULL, " ");
        }
        free(str);
    }
    int maxOccurrence = 0;
    char *result = NULL;
    for (int i = 0; i < totalWords; i++) {
        if (wordCounts[i].count > maxOccurrence) {
            maxOccurrence = wordCounts[i].count;
            result = wordCounts[i].word;
        }
    }
    return result;
}
