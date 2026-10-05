void find_synonyms(const char* word) {
    Word* word_entry = find_word(word);
    if (! (word_entry == NULL)) {
        printf("Synonyms for '%s':\n", word);
        for (int i = 0; ! (word_entry->synonyms[i] == NULL); i++) {
            printf("\t%s\n", word_entry->synonyms[i]);
        }
        printf("\nDefinitions and Example Sentences:\n");
        printf("Definition: %s\n", word_entry->definition);
        printf("Example Sentence: %s\n", word_entry->example);
    } else {
        printf("No synonyms found for '%s'.\n", word);
    }
}