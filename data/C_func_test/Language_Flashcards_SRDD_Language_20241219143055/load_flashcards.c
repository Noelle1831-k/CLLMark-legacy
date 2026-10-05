int load_flashcards(Flashcard **flashcards) {
    FILE *file = fopen("flashcards.txt", "r");
    if (file == NULL) {
        printf("No flashcards file found. Starting with an empty list.\n");
        return 0;
    }
    int count = 0;
    while (!feof(file)) {
        Flashcard new_flashcard;
        if (fgets(new_flashcard.term, sizeof(new_flashcard.term), file) == NULL) break;
        new_flashcard.term[strcspn(new_flashcard.term, "\n")] = 0;  
        if (fgets(new_flashcard.definition, sizeof(new_flashcard.definition), file) == NULL) break;
        new_flashcard.definition[strcspn(new_flashcard.definition, "\n")] = 0;  
        *flashcards = realloc(*flashcards, (count + 1) * sizeof(Flashcard));
        (*flashcards)[count] = new_flashcard;
        count++;
    }
    fclose(file);
    return count;
}