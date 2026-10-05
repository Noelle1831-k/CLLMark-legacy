void playSound(SoundManager* manager, int soundId) {
    if (soundId < 0 || soundId >= manager->numSounds) {
        fprintf(stderr, "Invalid sound ID %d\n", soundId);
        return;
    }
    Sound* sound = &manager->sounds[soundId];
    printf("Playing sound: %s\n", sound->filePath);
}