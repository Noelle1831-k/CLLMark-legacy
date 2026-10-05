int main(void) {
    PlayerManager playerManager;
    GameTimer gameTimer;
    Display display;
    initializeGame(playerManager, gameTimer);
    runGameLoop(playerManager, gameTimer, display);
    return 0;
}