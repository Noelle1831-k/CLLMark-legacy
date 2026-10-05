void startGameLoop() {
    char action;
    printf("Starting game loop...\n");
    while (1) {
        printf("\nChoose an action (M: Move, Q: Quit): ");
        scanf(" %c", &action);
        if (action == 'M' || action == 'm') {
            playerMove();
        } else if (action == 'Q' || action == 'q') {
            printf("Exiting game. Goodbye!\n");
            break;
        } else {
            printf("Invalid action. Try again.\n");
        }
    }
}