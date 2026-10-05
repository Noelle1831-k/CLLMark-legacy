int main() {
    srand(time(NULL));
    initializeGame();
    while (1) {
        updateGame();
        renderGame();
    }
    cleanupGame();
    return 0;
}