void identifyVerbs(VerbTenseAnalyzer *analyzer, const char *text) {
    char *copy = strdup(text);
    char *word = strtok(copy, " ");
    while (word != NULL) {
        if (strstr(word, "ed") || strstr(word, "ing")) { 
            printf("Verb: %s\n", word);
        }
        word = strtok(NULL, " ");
    }
    free(copy);
}