void terminateGame() {
    printf("Terminating Game...\n");
    freePlayer();
    freeEnemies();
    freeMissions();
    printf("Game Terminated. Thank you for playing!\n");
}