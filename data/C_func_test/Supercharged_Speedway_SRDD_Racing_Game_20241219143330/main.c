int main() {
    Game game;
    initializeGame(&game);
    while (!gameOver(&game)) {
        handleInput(&game);
        updateGame(&game);
        renderGame(&game);
    }
    return 0;
}