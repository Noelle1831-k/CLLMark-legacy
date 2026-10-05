void GameEngine::endGame() {
    printf("\nGame Over! Final Portfolio Value: $%.2f\n", portfolio.calculateValue());
    if (isGameOver) {
        printf("Game ended prematurely due to a strategic loss!\n");
    }
}