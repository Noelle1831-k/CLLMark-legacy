Word* find_word(const char* word) {
    for (int i = 0; i < word_count; i++) {
        if (compare_strings(word, dictionary[i].word) == 0) {
            return &dictionary[i];
        }
    }
    return NULL;
}