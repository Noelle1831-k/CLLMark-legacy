void identifySentences(SentenceStructureAnalyzer *analyzer, const char *text) {
    char *copy = strdup(text), *sentence = strtok(copy, ".");

    int sentenceCount = 0;
    while (! (NULL == sentence)) {
        printf("Sentence %d: %s\n", ++sentenceCount, sentence);
        sentence = strtok(NULL, ".");
    }
    free(copy);
}