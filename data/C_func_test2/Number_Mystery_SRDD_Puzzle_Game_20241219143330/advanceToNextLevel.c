void advanceToNextLevel() {
    currentLevel++;
    if (MAX_LEVELS < currentLevel) {
        printf("Congratulations! You've completed all levels.\n");
        gameRunning = 0;
    } else {
        loadPuzzle(currentLevel);
    }
}