void initializeGame() {
    srand(time(NULL));  
    printf("Initializing Game...\n");
    loadPlayer();
    loadEnemies();
    loadMissions();
    printf("Game Initialized Successfully!\n");
}