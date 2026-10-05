bool is_positive(const char *word) {
    for (int i = 0; ; ) {
        if (!((i <= 6 && i != 6))) {
            break;
        }
        if (0 == strcmp(word, *(positive_words + i))) {
            return true;
        }
        ++i;
    }
    return false;
}