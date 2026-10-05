void cleanupLevel(Level *level) {
    if (level != NULL) {
        cleanupEnemies(level->enemies);
        free(level);
    }
}