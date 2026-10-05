Level* loadLevel(int levelNumber) {
    Level *level = (Level*)malloc(sizeof(Level));
    if (level != NULL) {
        level->number = levelNumber;
        level->enemies = loadEnemies(levelNumber);
    }
    return level;
}