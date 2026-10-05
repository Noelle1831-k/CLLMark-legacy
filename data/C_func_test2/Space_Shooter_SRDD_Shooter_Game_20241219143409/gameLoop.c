void gameLoop() {
    int level = 1;
    while (level <= MAX_LEVELS) {
        printf("Starting Level %d...\n", level);
        initLevel(level);
        while (!isLevelComplete()) {
            clearScreen();
            handleInput();
            updateSpaceship();
            updateAliens();
            updateAsteroids();
            updateBoss(level);
            checkCollisions();
            renderGame();
            delay(50); 
        }
        level++;
    }
    printf("Congratulations! You have saved the galaxy!\n");
}