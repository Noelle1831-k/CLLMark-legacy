void startGame() {
    printf("Welcome to Business Tycoon!\n");
    initializeBusiness();
    int gameRunning = 1;
    while (gameRunning) {
        processTurn();
        displayMenu();
        int choice = getUserChoice();
        if (choice == 6) {
            printf("Exiting the game. Thank you for playing!\n");
            gameRunning = 0;
        }
    }
}