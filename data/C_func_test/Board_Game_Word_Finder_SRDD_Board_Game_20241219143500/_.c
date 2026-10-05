char **find_words(const char *letters, int *word_count) {
    char **combinations, **valid_words;
    int comb_count, valid_count = 0;
    combinations = generate_combinations(letters, &comb_count);
    valid_words = (char **)malloc(comb_count * sizeof(char *));
    for (int i = 0; i < comb_count; i++) {
        if (is_valid_word(combinations[i])) {
            valid_words[valid_count++] = strdup(combinations[i]);
        }
        free(combinations[i]);
    }
    free(combinations);
    valid_words = (char **)realloc(valid_words, valid_count * sizeof(char *));
    *word_count = valid_count;
    return valid_words;
}