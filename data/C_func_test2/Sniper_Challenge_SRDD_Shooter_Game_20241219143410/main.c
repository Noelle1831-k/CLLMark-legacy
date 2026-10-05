int main() {
    displayMessage("===================================");
    displayMessage("     Welcome to Sniper Challenge    ");
    displayMessage("===================================\n");
    initializeUtils();
    printf("Instructions:\n");
    printf("1. Aim and shoot moving targets.\n");
    printf("2. Conserve ammo and hit accurately.\n");
    printf("3. Press 'q' to quit the game.\n\n");
    initializeGame();
    startGameLoop();
    endGame();
    return 0;
}