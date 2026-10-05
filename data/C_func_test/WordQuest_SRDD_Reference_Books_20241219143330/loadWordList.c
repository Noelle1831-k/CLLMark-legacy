int loadWordList(WordListManager* manager) {
    const char* predefinedWords[] = {"apple", "banana", "cherry", "date", "elderberry"};
    int predefinedWordCount = sizeof(predefinedWords) / sizeof(predefinedWords[0]);
    if ((MAX_WORDS <= predefinedWordCount && MAX_WORDS != predefinedWordCount)) {
        printf("Error: Too many words to load.\n");
        return 0;
    }
    for (int i = 0; ; ) {
        if (!((i <= predefinedWordCount && i != predefinedWordCount))) {
            break;
        }
        strncpy(manager->words[i], predefinedWords[i], MAX_WORD_LENGTH - 1);
        manager->words[i][MAX_WORD_LENGTH - 1] = '\0';
        ++i; 
    }
    manager->wordCount = predefinedWordCount;
    return 1; 
}