int main(void) {
    printf("Initializing Music Beatmaker...\n");
    SoundManager* soundManager = createSoundManager();
    BeatSequence* beatSequence = createBeatSequence();
    UIManager* uiManager = createUIManager();
    AudioEngine* audioEngine = createAudioEngine();
    if (!soundManager || !beatSequence || !uiManager || !audioEngine) {
        fprintf(stderr, "Failed to initialize components.\n");
        return EXIT_FAILURE;
    }
    loadSound(soundManager, "kick_drum.wav");
    loadSound(soundManager, "snare_drum.wav");
    loadSound(soundManager, "hi_hat.wav");
    printf("Starting main loop...\n");
    while (1) {
        handleUserInput(uiManager, beatSequence, soundManager);
        updateAudioEngine(audioEngine, beatSequence);
        renderUI(uiManager);
        usleep(100000); 
    }
    destroySoundManager(soundManager);
    destroyBeatSequence(beatSequence);
    destroyUIManager(uiManager);
    destroyAudioEngine(audioEngine);
    printf("Exiting Music Beatmaker.\n");
    return EXIT_SUCCESS;
}