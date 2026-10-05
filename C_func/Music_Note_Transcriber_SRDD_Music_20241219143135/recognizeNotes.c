char *recognizeNotes(double *features) {
    char *transcription = (char *)malloc(100 * sizeof(char));
    if (!transcription) {
        fprintf(stderr, "Memory allocation failed for transcription.\n");
        exit(1);
    }
    strcpy(transcription, "");
    for (int i = 0; i < 10; i++) {
        strcat(transcription, notes[i % 7]);
        strcat(transcription, " ");
    }
    return transcription;
}