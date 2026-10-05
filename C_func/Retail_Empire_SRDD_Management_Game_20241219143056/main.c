int main() {
    srand(time(NULL)); 
    initializeGame();
    gameLoop();
    endGame();
    return 0;
}