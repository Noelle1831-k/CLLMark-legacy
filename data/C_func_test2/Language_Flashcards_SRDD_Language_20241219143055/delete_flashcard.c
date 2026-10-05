void delete_flashcard(Flashcard **flashcards, int *num_flashcards) {
    int index;
    printf("Enter the index of the flashcard to delete: ");
    if (scanf("%d", &index) != 1 || index < 0 || index >= *num_flashcards) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        pause();
        return;
    }
    getchar();
    for (int i = index; i < *num_flashcards - 1; i++) {
        (*flashcards)[i] = (*flashcards)[i + 1];
    }
    Flashcard *temp = realloc(*flashcards, (*num_flashcards - 1) * sizeof(Flashcard));
    if (temp == NULL && *num_flashcards > 1) {
        printf("Memory reallocation failed.\n");
        free(*flashcards);
        exit(EXIT_FAILURE);
    }
    *flashcards = temp;
    (*num_flashcards)--;
    printf("Flashcard deleted successfully!\n");
    pause();
}