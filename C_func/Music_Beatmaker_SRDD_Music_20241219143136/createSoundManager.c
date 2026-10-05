SoundManager* createSoundManager() {
    SoundManager* manager = (SoundManager*)malloc(sizeof(SoundManager));
    if (!manager) {
        fprintf(stderr, "Failed to allocate SoundManager.\n");
        return NULL;
    }
    manager->sounds = NULL;
    manager->numSounds = 0;
    return manager;
}