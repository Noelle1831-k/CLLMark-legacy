void edit_flashcard(Flashcard *flashcards, int num_flashcards) {
    int index;
    printf("Enter the index of the flashcard to edit: ");
    if (scanf("%d", &index) != 1 || index < 0 || index >= num_flashcards) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        pause();
        return;
    }
    getchar();
    printf("Editing flashcard: %s\n", flashcards[index].term);
    printf("Enter new definition: ");
    if (fgets(flashcards[index].definition, sizeof(flashcards[index].definition), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    flashcards[index].definition[strcspn(flashcards[index].definition, "\n")] = 0;
    printf("Flashcard updated successfully!\n");
    pause();
}