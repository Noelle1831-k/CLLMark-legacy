void extractInstrumentation(const char *audioData, int *instrumentation) {
    *instrumentation = (int)(strlen(audioData) % 100);
}