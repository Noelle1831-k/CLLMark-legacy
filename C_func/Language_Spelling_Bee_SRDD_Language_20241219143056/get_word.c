char *get_word(int difficulty) {
    int filtered_words[MAX_WORDS];
    int filtered_count = 0;
    for (int i = 0; i < word_count; i++) {
        if (word_list[i].difficulty == difficulty) {
            filtered_words[filtered_count++] = i;
        }
    }
    if (filtered_count == 0) {
        return NULL;
    }
    int random_index = random_int(0, filtered_count - 1);
    return word_list[filtered_words[random_index]].word;
}