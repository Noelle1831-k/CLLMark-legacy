int main() {
    Game game;
    initializeGame(&game);
    while (!gameOver(&game)) {
        displayGameStatus(&game);
        executeMission(&game);
    }
    concludeGame(&game);
    return 0;
}