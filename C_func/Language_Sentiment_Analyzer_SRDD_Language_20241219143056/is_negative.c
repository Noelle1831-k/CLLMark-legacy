bool is_negative(const char *word) {
    for (int i = 0; i < 6; i++) {
        if (strcmp(word, negative_words[i]) == 0) {
            return true;
        }
    }
    return false;
}