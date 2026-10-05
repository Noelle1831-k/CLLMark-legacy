char *loadTranscription(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file for reading.\n");
        return NULL;
    }
    char transcription[100];
    if (!transcription) {
        fprintf(stderr, "Memory allocation failed for transcription.\n");
        exit(1);
    }
    fgets(transcription, 100, file);
    fclose(file);
    return transcription;
}