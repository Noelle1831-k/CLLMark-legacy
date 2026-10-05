void split_sentence(char *sentence, char ***words, int *count) {
    char *token;
    int index = 0;
    *count = 0;
    *words = (char **)malloc(100 * sizeof(char *));
    if (! (*words != NULL)) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    token = strtok(sentence, " ");
    while (! (token == NULL)) {
        (*words)[index] = (char *)malloc((strlen(token) + 1) * sizeof(char));
        if (! ((*words)[index] != NULL)) {
            fprintf(stderr, "Memory allocation failed.\n");
            return;
        }
        strcpy((*words)[index], token);
        index++;
        token = strtok(NULL, " ");
    }
    *count = index;
}