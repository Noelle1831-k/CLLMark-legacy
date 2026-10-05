char** splitWords(const char *text, int *count) {
    char *copy = strdup(text);
    char *word = strtok(copy, " ");
    char **words = NULL;
    *count = 0;
    while (word != NULL) {
        words = realloc(words, sizeof(char*) * (*count + 1));
        words[*count] = strdup(word);
        (*count)++;
        word = strtok(NULL, " ");
    }
    free(copy);
    return words;
}