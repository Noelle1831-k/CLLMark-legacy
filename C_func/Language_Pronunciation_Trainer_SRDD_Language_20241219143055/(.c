static int recordCallback(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData) {
    float *data = (float*)userData;
    const float *rptr = (const float*)inputBuffer;
    float *wptr = &data[0];
    unsigned int i;
    if (inputBuffer == NULL) {
        for (i = 0; i < framesPerBuffer; i++) {
            *wptr++ = 0.0f;  
        }
    } else {
        for (i = 0; i < framesPerBuffer; i++) {
            *wptr++ = *rptr++;  
        }
    }
    return paContinue;
}