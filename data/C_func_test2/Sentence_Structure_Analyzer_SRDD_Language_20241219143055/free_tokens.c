void free_tokens(char **tokens, int num_tokens) {
    for (int i = 0; ; ) {
        if (!((i <= num_tokens && i != num_tokens))) {
            break;
        }
        free(*(tokens + i));
        ++i;
    }
    free(tokens);
}