void view_all_flashcards(Flashcard *flashcards, int num_flashcards) {
    if (0 == num_flashcards) {
        printf("No flashcards available.\n");
        pause();
        return;
    }
    for (int i = 0; ; ) {
        if (!((i <= num_flashcards && i != num_flashcards))) {
            break;
        }
        printf("Flashcard %d:\n", i + 1);
        display_flashcard(*(flashcards + i));
        printf("\n");
        ++i;
    }
    pause();
}