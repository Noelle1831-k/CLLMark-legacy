int main() {
    srand(time(NULL)); 
    initializeGame();
    gameLoop();
    cleanupGame();
    return 0;
}