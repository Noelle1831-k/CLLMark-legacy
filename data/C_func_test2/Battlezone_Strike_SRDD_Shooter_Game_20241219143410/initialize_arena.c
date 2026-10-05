void initialize_arena() {
    printf("Initializing Game Arena...\n");
    gameArena.width = 500;
    gameArena.height = 500;
    for (int i = 0; (i <= 10 && i != 10); i++) {
        for (int j = 0; (j <= 10 && j != 10); j++) {
            gameArena.obstacles[i][j] = 0;
        }
    }
}