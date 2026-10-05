void tagPartsOfSpeech(PartsOfSpeechTagger *tagger, const char *text) {
    char *copy = strdup(text);
    char *word = strtok(copy, " ");
    while (word != NULL) {
        printf("Word: %s, POS: N/A\n", word); 
        word = strtok(NULL, " ");
    }
    free(copy);
}