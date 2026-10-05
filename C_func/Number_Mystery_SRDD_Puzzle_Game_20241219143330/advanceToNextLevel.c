void advanceToNextLevel() {
    currentLevel++;
    if (currentLevel > MAX_LEVELS) {
        printf("Congratulations! You've completed all levels.\n");
        gameRunning = 0;
    } else {
        loadPuzzle(currentLevel);
    }
}