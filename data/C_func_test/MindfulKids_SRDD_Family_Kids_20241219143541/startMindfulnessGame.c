void startMindfulnessGame() {
    printf("\n=== Mindfulness Games ===\n");
    printf("1. Memory Game\n");
    printf("2. Matching Game\n");
    printf("Select a game (1-2): ");
    int choice = getValidatedInput(1, 2);
    if (choice == 1) {
        printf("Let's play a memory game!\n");
        srand(time(NULL));
        int randomNumber = rand() % 100 + 1;
        printf("Remember this number: %d\n", randomNumber);
        sleep(5);
        printf("\033[H\033[J"); 
        printf("What was the number? ");
        int userGuess;
        scanf("%d", &userGuess);
        if (userGuess == randomNumber) {
            printf("Correct! Great memory!\n");
        } else {
            printf("Oops! The correct number was %d. Try again next time!\n", randomNumber);
        }
    } else if (choice == 2) {
        printf("Matching Game: Match the emotion to the correct face!\n");
        printf("This feature is under development. Stay tuned!\n");
    }
}