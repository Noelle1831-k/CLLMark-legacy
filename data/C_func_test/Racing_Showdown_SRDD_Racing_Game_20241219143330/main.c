int main() {
    srand(time(0)); 
    int choice;
    Game game;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            initializeGame(&game);
            startRace(&game);
        } else if (choice == 2) {
            printf("Exiting the game. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}