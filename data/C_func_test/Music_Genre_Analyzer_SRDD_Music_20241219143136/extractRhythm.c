void extractRhythm(const char *audioData, int *rhythm) {
    *rhythm = (int)(strlen(audioData) % 100);
}