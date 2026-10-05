typedef struct {
    char word[31];
    int pages[101];
    int page_count;
} WordEntry;
int compareWords(const void *a, const void *b) {
    return strcmp(((WordEntry *)a)->word, ((WordEntry *)b)->word);
}
int comparePages(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}
void processInputPairs() {
    WordEntry entries[100];
    int entryCount = 0;
    char word[31];
    int pageNumber;
    int i, j;
    int index;
    while (scanf("%30s %d", word, &pageNumber) != EOF) {
        index = -1;
        for (i = 0; i < entryCount; i++) {
            if (strcmp(entries[i].word, word) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            index = entryCount++;
            strcpy(entries[index].word, word);
            entries[index].page_count = 0;
        }
        entries[index].pages[entries[index].page_count++] = pageNumber;
    }
    for (i = 0; i < entryCount; i++) {
        qsort(entries[i].pages, entries[i].page_count, sizeof(int), comparePages);
    }
    qsort(entries, entryCount, sizeof(WordEntry), compareWords);
    for (i = 0; i < entryCount; i++) {
        printf("%s", entries[i].word);
        for (j = 0; j < entries[i].page_count; j++) {
            printf(" %d", entries[i].pages[j]);
        }
        printf("\n");
    }
}