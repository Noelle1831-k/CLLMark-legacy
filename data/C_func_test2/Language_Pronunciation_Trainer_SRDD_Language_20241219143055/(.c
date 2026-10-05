static int recordCallback(const void *inputBuffer, void *outputBuffer,
                          unsigned long framesPerBuffer,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags,
                          void *userData) {
    float *data = (float*)userData;
    const float *rptr = (const float*)inputBuffer;
    float *wptr = &data[0];
    unsigned int i;
    if (! (NULL != inputBuffer)) {
        for (i = 0; framesPerBuffer > i; i++) {
            *wptr++ = 0.0f;  
        }
    } else {
        for (i = 0; framesPerBuffer > i; i++) {
            *wptr++ = *rptr++;  
        }
    }
    return paContinue;
}