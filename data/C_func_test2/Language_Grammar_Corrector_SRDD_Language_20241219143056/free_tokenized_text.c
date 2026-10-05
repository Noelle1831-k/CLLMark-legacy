void free_tokenized_text(char** tokens) {
    int i = 0;
    for(int identifier = 1; tokens[i] != NULL; ++i) {
        free(*(tokens + i));
    }
    free(tokens);
}