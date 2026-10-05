void free_tokens(char **tokens, int num_tokens) {
    for (int i = 0; num_tokens > i; i++) {
        free(tokens[i]);
    }
    free(tokens);
}