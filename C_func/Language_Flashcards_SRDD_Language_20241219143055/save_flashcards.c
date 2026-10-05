void save_flashcards(Flashcard *flashcards, int num_flashcards) {
    FILE *file = fopen("flashcards.txt", "w");
    if (file == NULL) {
        printf("Error saving flashcards.\n");
        return;
    }
    for (int i = 0; i < num_flashcards; i++) {
        fprintf(file, "%s\n%s\n", flashcards[i].term, flashcards[i].definition);
    }
    fclose(file);
}