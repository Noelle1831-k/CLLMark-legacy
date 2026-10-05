void destroySoundManager(SoundManager* manager) {
    if (manager) {
        free(manager->sounds);
        free(manager);
    }
}