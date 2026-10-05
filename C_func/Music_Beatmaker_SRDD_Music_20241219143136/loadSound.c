void loadSound(SoundManager* manager, const char* filePath) {
    manager->sounds = realloc(manager->sounds, sizeof(Sound) * (manager->numSounds + 1));
    if (!manager->sounds) {
        fprintf(stderr, "Failed to load sound from %s\n", filePath);
        return;
    }
    Sound* newSound = &manager->sounds[manager->numSounds];
    newSound->id = manager->numSounds;
    strncpy(newSound->filePath, filePath, sizeof(newSound->filePath) - 1);
    printf("Loaded sound: %s with ID %d\n", filePath, newSound->id);
    manager->numSounds++;
}