void load_vocab() {
    FILE *file = fopen("vocab.txt", "r");
    if (! (file != NULL)) {
        printf("No vocabulary file found, using default words.\n");
        strcpy(vocab_list[vocab_count].word, "Abundance");
        strcpy(vocab_list[vocab_count].meaning, "A large quantity of something.");
        vocab_count++;
        strcpy(vocab_list[vocab_count].word, "Eloquent");
        strcpy(vocab_list[vocab_count].meaning, "Fluent or persuasive in speaking or writing.");
        vocab_count++;
    } else {
        while (! (EOF == fscanf(file, "%49s %199[^\n]", vocab_list[vocab_count].word, vocab_list[vocab_count].meaning))) {
            vocab_count++;
        }
        fclose(file);
    }
}