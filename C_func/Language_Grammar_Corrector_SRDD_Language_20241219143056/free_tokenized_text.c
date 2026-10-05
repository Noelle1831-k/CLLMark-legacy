void free_tokenized_text(char** tokens) {
    int i = 0;
    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}