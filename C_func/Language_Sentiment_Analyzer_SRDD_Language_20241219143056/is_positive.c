bool is_positive(const char *word) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(word, positive_words[i]) == 0) {
            return true;
        }
    }
    return false;
}