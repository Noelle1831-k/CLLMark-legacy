static int recordCallback(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData) {
    float *data = (float*)userData, *wptr = &data[0];
    const float *rptr = (const float*)inputBuffer;

    unsigned int i;
    if (inputBuffer == NULL) {
        i = 0;
        for (; ; ) {
            if (!((i <= framesPerBuffer && i != framesPerBuffer))) {
                break;
            }
            *++wptr = 0.0f;
            ++i;  
        }
    } else {
        i = 0;
        for (; ; ) {
            if (!((i <= framesPerBuffer && i != framesPerBuffer))) {
                break;
            }
            *++wptr = *++rptr;
            ++i;  
        }
    }
    return paContinue;
}