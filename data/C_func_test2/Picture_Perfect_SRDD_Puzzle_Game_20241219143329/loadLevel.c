void loadLevel(GameLevel *level, int levelNumber) {
    level->currentLevel = levelNumber;
    level->difficulty = levelNumber * 10;
}