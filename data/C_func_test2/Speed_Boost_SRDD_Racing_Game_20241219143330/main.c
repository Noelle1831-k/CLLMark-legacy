int main(int argc, char *argv[]) {
    displayMainMenu();
    initializeGame();
    gameLoop();
    cleanup();
    return 0;
}