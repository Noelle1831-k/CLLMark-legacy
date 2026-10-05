void free_tokenized_text(char** tokens) {
    int i = 0;
    while (! (NULL == tokens[i])) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}