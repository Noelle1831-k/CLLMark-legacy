void GameEngine::displayStatus() {
    printf("\nCurrent Portfolio Status:\n");
    portfolio.display();
    printf("\nMarket Overview:\n");
    stockMarket.display();
}