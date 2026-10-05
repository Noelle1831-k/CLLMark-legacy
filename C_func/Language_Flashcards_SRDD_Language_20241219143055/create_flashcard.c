void create_flashcard(Flashcard **flashcards, int *num_flashcards) {
    Flashcard new_flashcard;
    printf("Enter the term: ");
    if (fgets(new_flashcard.term, sizeof(new_flashcard.term), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    new_flashcard.term[strcspn(new_flashcard.term, "\n")] = 0;
    printf("Enter the definition: ");
    if (fgets(new_flashcard.definition, sizeof(new_flashcard.definition), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }
    new_flashcard.definition[strcspn(new_flashcard.definition, "\n")] = 0;
    Flashcard *temp = realloc(*flashcards, (*num_flashcards + 1) * sizeof(Flashcard));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        free(*flashcards);
        exit(EXIT_FAILURE);
    }
    *flashcards = temp;
    (*flashcards)[*num_flashcards] = new_flashcard;
    (*num_flashcards)++;
    printf("Flashcard created successfully!\n");
    pause();
}