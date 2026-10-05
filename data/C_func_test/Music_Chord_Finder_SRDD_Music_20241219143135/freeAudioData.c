void freeAudioData(AudioData *audioData) {
    if (audioData) {
        free(audioData->data);
        free(audioData);
    }
}