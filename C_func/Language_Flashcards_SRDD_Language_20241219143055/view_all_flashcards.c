void view_all_flashcards(Flashcard *flashcards, int num_flashcards) {
    if (num_flashcards == 0) {
        printf("No flashcards available.\n");
        pause();
        return;
    }
    for (int i = 0; i < num_flashcards; i++) {
        printf("Flashcard %d:\n", i + 1);
        display_flashcard(flashcards[i]);
        printf("\n");
    }
    pause();
}