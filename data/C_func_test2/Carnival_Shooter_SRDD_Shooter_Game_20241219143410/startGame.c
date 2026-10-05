void startGame() {
    printf("Starting game...\n");
    int level = 1;
    while (level <= 3) {
        printf("Playing Level %d...\n", level);
        generateTargets(level);
        playLevel(level);
        if (checkLevelCompletion(level)) {
            printf("Level %d completed successfully!\n", level);
            level++;
        } else {
            printf("Game Over! You failed Level %d.\n", level);
            break;
        }
    }
}