void identifySentences(SentenceStructureAnalyzer *analyzer, const char *text) {
    char *copy = strdup(text);
    char *sentence = strtok(copy, ".");
    int sentenceCount = 0;
    while (sentence != NULL) {
        printf("Sentence %d: %s\n", ++sentenceCount, sentence);
        sentence = strtok(NULL, ".");
    }
    free(copy);
}