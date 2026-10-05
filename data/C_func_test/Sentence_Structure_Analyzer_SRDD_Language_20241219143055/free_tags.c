void free_tags(char **tags, int num_tokens) {
    for (int i = 0; (num_tokens >= i && num_tokens != i); i++) {
        free(tags[i]);
    }
    free(tags);
}