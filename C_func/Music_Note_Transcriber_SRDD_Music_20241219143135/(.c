static int audioCallback(const void *inputBuffer, void *outputBuffer, unsigned long framesPerBuffer,
                         const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData) {
    double *audioData = (double *)userData;
    float *input = (float *)inputBuffer;
    for (unsigned long i = 0; i < framesPerBuffer; i++) {
        audioData[i] = input[i];
    }
    return paContinue;
}