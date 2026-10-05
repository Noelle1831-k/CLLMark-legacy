void handleUserChoice(int choice) {
    static int gameInitialized = 0;
    switch (choice) {
        case 1:
            if (!gameInitialized) {
                initializeGame();
                gameInitialized = 1;
                printf("Game Initialized!\n");
            } else {
                printf("Game already initialized.\n");
            }
            break;
        case 2:
            if (gameInitialized) {
                int teamId, score;
                printf("Enter Team ID (0 or 1): ");
                teamId = validateInput(0, 1);
                printf("Enter New Score: ");
                scanf("%d", &score);
                updateScore(teamId, score);
            } else {
                printf("Please initialize the game first.\n");
            }
            break;
        case 3:
            if (gameInitialized) {
                displayGameStats();
            } else {
                printf("Please initialize the game first.\n");
            }
            break;
        case 4:
            if (gameInitialized) {
                resetGame();
                gameInitialized = 0;
                printf("Game has been reset.\n");
            } else {
                printf("Game is not initialized to reset.\n");
            }
            break;
        case 5:
            printf("Exiting... Thank you for using the Sports Score Tracker.\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
    }
}