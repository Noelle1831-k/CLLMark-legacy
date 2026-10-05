int main(void) {
    displayMainMenu();
    initializeGame();
    gameLoop();
    cleanup();
    return 0;
}