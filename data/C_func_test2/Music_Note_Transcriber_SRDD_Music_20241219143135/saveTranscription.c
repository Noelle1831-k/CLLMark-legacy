void saveTranscription(const char *fileName, const char *transcription) {
    FILE *file = fopen(fileName, "w");
    if (!file) {
        fprintf(stderr, "Failed to open file for writing.\n");
        return;
    }
    fprintf(file, "%s\n", transcription);
    fclose(file);
}