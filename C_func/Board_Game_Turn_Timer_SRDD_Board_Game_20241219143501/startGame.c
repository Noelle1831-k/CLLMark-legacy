void startGame() {
    char userInput[10];
    while (1) {
        char* currentPlayer = getCurrentPlayer();
        displayCurrentPlayer(currentPlayer);
        startTimer(30);
        printf("Type 'quit' to end the game or press Enter to continue: ");
        fgets(userInput, sizeof(userInput), stdin);
        if (strncmp(userInput, "quit", 4) == 0) {
            break;
        }
        nextPlayer();
    }
}