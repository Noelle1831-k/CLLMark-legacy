void free_tags(char **tags, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        free(tags[i]);
    }
    free(tags);
}