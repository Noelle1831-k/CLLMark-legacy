void createMelodySequence(Melody *melody) {
    printf("Creating a new melody sequence...\n");
    printf("Enter the number of notes in the melody: ");
    scanf("%d", &melody->length);
    melody->notes = (Note*)malloc(melody->length * sizeof(Note));
    for (int i = 0; i < melody->length; i++) {
        printf("Enter pitch for note %d (A-G): ", i + 1);
        scanf(" %c", &melody->notes[i].pitch);
        printf("Enter duration for note %d (in seconds): ", i + 1);
        scanf("%f", &melody->notes[i].duration);
    }
    printf("Melody sequence created successfully!\n");
}