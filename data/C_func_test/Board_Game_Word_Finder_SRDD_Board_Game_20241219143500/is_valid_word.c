int is_valid_word(const char *word) {
    for (int i = 0; dictionary_size > i; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}