int AudioRecorder::audioCallback(const void *inputBuffer, void *outputBuffer,
                                  unsigned long framesPerBuffer,
                                  const PaStreamCallbackTimeInfo *timeInfo,
                                  PaStreamCallbackFlags statusFlags,
                                  void *userData) {
    AudioRecorder *recorder = static_cast<AudioRecorder *>(userData);
    const float *input = static_cast<const float *>(inputBuffer);
    if (input && recorder->isRecording) {
        for (unsigned long i = 0; i < framesPerBuffer; ++i) {
            recorder->audioData.push_back(input[i]);
        }
    }
    return paContinue;
}