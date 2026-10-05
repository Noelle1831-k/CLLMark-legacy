int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <audio_file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char audioFilePath[MAX_PATH_LENGTH];
    strncpy(audioFilePath, argv[1], MAX_PATH_LENGTH);
    AudioFeatures features;
    if (!processAudioFile(audioFilePath, &features)) {
        fprintf(stderr, "Error processing audio file.\n");
        return EXIT_FAILURE;
    }
    char genre[50];
    double confidence;
    if (!classifyGenre(&features, genre, &confidence)) {
        fprintf(stderr, "Error classifying genre.\n");
        return EXIT_FAILURE;
    }
    printf("Predicted Genre: %s\n", genre);
    printf("Confidence Score: %.2f\n", confidence);
    return EXIT_SUCCESS;
}