void display_vocab() {
    printf("\nVocabulary List:\n");
    for (int i = 0; i < vocab_count; i++) {
        printf("%d. %s - %s\n", i + 1, vocab_list[i].word, vocab_list[i].meaning);
    }
}