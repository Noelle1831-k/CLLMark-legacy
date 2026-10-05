int processAudioFile(const char *filePath, AudioFeatures *features) {
    char *audioData = NULL;
    if (!readFile(filePath, &audioData)) {
        return 0;
    }
    extractRhythm(audioData, &features->rhythm);
    extractMelody(audioData, &features->melody);
    extractInstrumentation(audioData, &features->instrumentation);
    free(audioData);
    return 1;
}