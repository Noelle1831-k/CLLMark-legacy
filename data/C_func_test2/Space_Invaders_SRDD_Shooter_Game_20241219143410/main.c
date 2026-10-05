int main() {
    srand(time(NULL)); 
    Game game;
    initializeGame(&game);
    while (!gameOver(&game)) {
        handleInput(&game.spaceship);
        updateGame(&game);
        renderGame(&game);
    }
    printf("Game Over! Your score: %d\n", game.score);
    return 0;
}