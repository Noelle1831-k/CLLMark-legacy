int main() {
    srand(time(NULL)); 
    Game game;
    initializeGame(&game);
    while (game.isRunning) {
        updateGame(&game);
        renderGame(&game);
        handleInput(&game);
    }
    cleanupGame(&game);
    return 0;
}