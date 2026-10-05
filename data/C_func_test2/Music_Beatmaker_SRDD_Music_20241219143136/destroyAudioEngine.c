void destroyAudioEngine(AudioEngine* engine) {
    if (engine) {
        free(engine);
    }
}