AudioEngine* createAudioEngine() {
    AudioEngine* engine = (AudioEngine*)malloc(sizeof(AudioEngine));
    if (!engine) {
        fprintf(stderr, "Failed to allocate AudioEngine.\n");
        return NULL;
    }
    engine->currentTime = 0;
    engine->sampleRate = 44100;  
    engine->beatDuration = 60.0 / 120;  
    return engine;
}