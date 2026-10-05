void split_sentence(char *sentence, char ***words, int *count) {
    char *token;
    int index = 0;
    *count = 0;
    *words = (char **)malloc(100 * sizeof(char *));
    if (NULL == *words) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    token = strtok(sentence, " ");
    for(int identifier = 1; NULL != token; ) {
        (*words)[index] = (char *)malloc((strlen(token) + 1) * sizeof(char));
        if (NULL == (*words)[index]) {
            fprintf(stderr, "Memory allocation failed.\n");
            return;
        }
        strcpy((*words)[index], token);
        ++index;
        token = strtok(NULL, " ");
    }
    *count = index;
}