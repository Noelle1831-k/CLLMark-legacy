void extractMelody(const char *audioData, int *melody) {
    *melody = (int)(strlen(audioData) % 100);
}