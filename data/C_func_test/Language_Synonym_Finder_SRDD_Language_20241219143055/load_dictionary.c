void load_dictionary(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to load dictionary file: %s\n", filename);
        return;
    }
    word_count = 0;
    char buffer[1024];
    while (fgets(dictionary[word_count].word, sizeof(dictionary[word_count].word), file) != NULL) {
        dictionary[word_count].word[strcspn(dictionary[word_count].word, "\n")] = '\0';
        char synonym_line[1024];
        if (fgets(synonym_line, sizeof(synonym_line), file) == NULL) {
            printf("Error: Missing synonyms for word '%s'. Skipping entry.\n", dictionary[word_count].word);
            continue;
        }
        parse_synonyms(synonym_line, dictionary[word_count].synonyms);
        if (fgets(dictionary[word_count].definition, sizeof(dictionary[word_count].definition), file) == NULL) {
            printf("Error: Missing definition for word '%s'. Skipping entry.\n", dictionary[word_count].word);
            continue;
        }
        if (fgets(dictionary[word_count].example, sizeof(dictionary[word_count].example), file) == NULL) {
            printf("Error: Missing example sentence for word '%s'. Skipping entry.\n", dictionary[word_count].word);
            continue;
        }
        dictionary[word_count].definition[strcspn(dictionary[word_count].definition, "\n")] = '\0';
        dictionary[word_count].example[strcspn(dictionary[word_count].example, "\n")] = '\0';
        word_count++;
        if (word_count >= MAX_WORDS) {
            printf("Warning: Maximum dictionary size reached. Additional entries ignored.\n");
            break;
        }
    }
    fclose(file);
}