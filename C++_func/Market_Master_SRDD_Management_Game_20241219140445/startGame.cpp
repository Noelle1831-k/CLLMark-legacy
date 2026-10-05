void GameEngine::startGame() {
    printf("Welcome to Market Master!\n");
    srand((unsigned int)time(NULL));
    for (int round = 1; round <= gameRounds && !isGameOver; round++) {
        printf("\n--- Round %d ---\n", round);
        stockMarket.updatePrices();
        newsFeed.generateNews();
        player.makeDecision(portfolio, stockMarket);
        isGameOver = checkGameOver();
        if (isGameOver) {
            break;
        }
        displayStatus();
    }
    endGame();
}