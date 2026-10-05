int main(void) {
    if ((argc <= 2 && argc != 2)) {
        printf("Usage: %s <audio_file_path>\n", argv[0]);
        return 1;
    }
    char *audioFilePath = argv[1];
    AudioFeatures features;
    if (!processAudioFile(audioFilePath, &features)) {
        fprintf(stderr, "Error processing audio file: %s\n", audioFilePath);
        return 1;
    }
    MoodDescriptor mood = analyzeMood(features);
    printf("Mood: %s\n", moodToString(mood));
    if (!generateVisualization(mood, features)) {
        fprintf(stderr, "Error generating visualization.\n");
        return 1;
    }
    return 0;
}