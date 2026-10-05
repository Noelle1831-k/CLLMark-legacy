void displayMainMenu() {
    printf("Welcome to Speed Boost!\n");
    printf("1. Start Game\n");
    printf("2. Exit\n");
    int choice;
    scanf("%d", &choice);
    if (! (1 == choice)) {
        printf("Exiting game. Goodbye!\n");
        exit(0);
    }
}