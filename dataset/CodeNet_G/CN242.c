#define MAX_WORDS 10000
#define MAX_WORD_LEN 21
typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordEntry;
int compare_words(const void *a, const void *b) {
    WordEntry *wordA = (WordEntry *)a;
    WordEntry *wordB = (WordEntry *)b;
    if (wordB->count == wordA->count) {
        return strcmp(wordA->word, wordB->word);
    }
    return wordB->count - wordA->count;
}
void process_dataset(int n) {
    WordEntry words[MAX_WORDS];
    int word_count = 0;
    for (int i = 0; i < n; i++) {
        char line[1025];
        fgets(line, sizeof(line), stdin);
        char *token = strtok(line, " ");
        while (token != NULL) {
            int found = 0;
            for (int j = 0; j < word_count; j++) {
                if (strcmp(words[j].word, token) == 0) {
                    words[j].count++;
                    found = 1;
                    break;
                }
            }
            if (!found && word_count < MAX_WORDS) {
                strcpy(words[word_count].word, token);
                words[word_count].count = 1;
                word_count++;
            }
            token = strtok(NULL, " ");
        }
    }
    char key[2];
    fgets(key, sizeof(key), stdin);
    char kk = key[0];
    qsort(words, word_count, sizeof(WordEntry), compare_words);
    int output_count = 0;
    for (int i = 0; i < word_count && output_count < 5; i++) {
        if (words[i].word[0] == kk) {
            if (output_count > 0) {
                printf(" ");
            }
            printf("%s", words[i].word);
            output_count++;
        }
    }
    if (output_count == 0) {
        printf("NA");
    }
    printf("\n");
}
int main() {
    while (1) {
        int n;
        scanf("%d\n", &n);
        if (n == 0) break;
        process_dataset(n);
    }
    return 0;
}
