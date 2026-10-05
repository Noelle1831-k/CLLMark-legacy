int main() {
    srand(time(NULL)); 
    printf("Welcome to the Board Game Strategy Analyzer!\n");
    GameState gameState;
    initializeGameState(&gameState);
    int continueGame = 1;
    while (continueGame) {
        printf("\nEnter your move and decision:\n");
        char move[50], decision[50];
        getPlayerInput(move, decision);
        if (!validateInput(move, decision)) {
            logError("Invalid input detected.");
            continue;
        }
        updateGameState(&gameState, move, decision);
        printf("\nCurrent Game State:\n");
        printGameState(&gameState);
        printf("\nDo you want to continue? (1 for Yes, 0 for No): ");
        scanf("%d", &continueGame);
    }
    printf("\nAnalyzing strategies...\n");
    analyzeStrategies(&gameState);
    printf("\nGenerating visualization...\n");
    generateVisualization(&gameState);
    printf("\nThank you for using the Board Game Strategy Analyzer!\n");
    return 0;
}