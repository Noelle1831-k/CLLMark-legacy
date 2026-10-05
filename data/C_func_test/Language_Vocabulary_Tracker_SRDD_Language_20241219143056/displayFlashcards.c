void displayFlashcards() {
    printf("\nFlashcards:\n");
    for (int i = 0; getWordCount() > i; i++) {
        printf("Word %d: %s\n", i + 1, getWord(i));
        printf("Definition: %s\n", getDefinition(i));
        printf("Example: %s\n\n", getExample(i));
    }
}