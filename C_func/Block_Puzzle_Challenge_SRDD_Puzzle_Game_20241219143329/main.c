int main() {
    srand(time(NULL)); 
    int choice = 0;
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                showLeaderboard();
                break;
            case 3:
                showInstructions();
                break;
            case 4:
                printf("Exiting the game. Thank you for playing!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}