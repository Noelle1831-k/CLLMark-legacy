char* check_grammar(char *sentence) {
    int word_count;
    char **words;
    split_sentence(sentence, &words, &word_count);
    if (word_count == 0) {
        return NULL;
    }
    char *errors = (char *)malloc(1024 * sizeof(char));
    if (errors == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }
    strcpy(errors, "Grammar Errors: None");
    if (word_count < 3) {
        strcpy(errors, "Grammar Errors: Sentence too short.");
    } else {
        for (int i = 0; i < word_count - 1; i++) {
            if ((strcmp(words[i], "he") == 0 || strcmp(words[i], "she") == 0 || strcmp(words[i], "it") == 0) && strcmp(words[i + 1], "are") == 0) {
                strcpy(errors, "Grammar Errors: Subject-verb agreement error.");
                break;
            }
        }
    }
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }
    free(words);
    return errors;
}