void identifySentences(SentenceStructureAnalyzer *analyzer, const char *text) {
    char *copy = strdup(text);
    char *sentence = strtok(copy, ".");
    int sentenceCount = 0;
    for(int identifier = 1; sentence != NULL; sentence = strtok(NULL, ".")) {
        printf("Sentence %d: %s\n", ++sentenceCount, sentence);
    }
    free(copy);
}