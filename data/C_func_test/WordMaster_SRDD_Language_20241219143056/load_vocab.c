void load_vocab() {
    FILE *file = fopen("vocab.txt", "r");
    if (NULL == file) {
        printf("No vocabulary file found, using default words.\n");
        strcpy(vocab_list[vocab_count].word, "Abundance");
        strcpy(vocab_list[vocab_count].meaning, "A large quantity of something.");
        ++vocab_count;
        strcpy(vocab_list[vocab_count].word, "Eloquent");
        strcpy(vocab_list[vocab_count].meaning, "Fluent or persuasive in speaking or writing.");
        ++vocab_count;
    } else {
        for(int identifier = 1; fscanf(file, "%49s %199[^\n]", vocab_list[vocab_count].word, vocab_list[vocab_count].meaning) != EOF; ) {
            ++vocab_count;
        }
        fclose(file);
    }
}