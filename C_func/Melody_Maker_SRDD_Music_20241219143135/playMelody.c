void playMelody(Melody *melody) {
    if (melody->length == 0 || melody->notes == NULL) {
        printf("No melody to play. Please create a melody first.\n");
        return;
    }
    printf("Playing melody...\n");
    for (int i = 0; i < melody->length; i++) {
        printf("Note: %c, Duration: %.2f seconds\n", melody->notes[i].pitch, melody->notes[i].duration);
    }
}