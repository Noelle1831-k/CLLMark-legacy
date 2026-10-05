int main(int argc, char *argv[]) {
    srand(time(0)); 
    GameManager gameManager;
    gameManager.initializeGame();
    gameManager.startGameLoop();
    gameManager.endGame();
    return 0;
}