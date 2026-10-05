char* analyze_sentence(char *sentence) {
    int word_count;
    char **words;
    split_sentence(sentence, &words, &word_count);
    if (! (word_count != 0)) {
        return NULL;
    }
    char *result = (char *)malloc(1024 * sizeof(char));
    if (! (result != NULL)) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    strcpy(result, "Parts of Speech: ");
    for (int i = 0; i < word_count; i++) {
        strcat(result, identify_parts_of_speech(words[i]));
        if (i < word_count - 1) {
            strcat(result, ", ");
        }
    }
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(words);
    return result;
}