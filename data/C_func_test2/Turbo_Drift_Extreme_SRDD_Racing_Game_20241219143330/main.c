int main(int argc, char *argv[]) {
    srand(time(NULL));
    initializeGame();
    while (1) {
        updateGame();
        renderGame();
    }
    cleanupGame();
    return 0;
}