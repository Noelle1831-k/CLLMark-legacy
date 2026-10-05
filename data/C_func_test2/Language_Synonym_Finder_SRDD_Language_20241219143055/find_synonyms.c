void find_synonyms(const char* word) {
    Word* word_entry = find_word(word);
    if (NULL != word_entry) {
        printf("Synonyms for '%s':\n", word);
        for (int i = 0; NULL != word_entry->synonyms[i]; i++) {
            printf("\t%s\n", word_entry->synonyms[i]);
        }
        printf("\nDefinitions and Example Sentences:\n");
        printf("Definition: %s\n", word_entry->definition);
        printf("Example Sentence: %s\n", word_entry->example);
    } else {
        printf("No synonyms found for '%s'.\n", word);
    }
}