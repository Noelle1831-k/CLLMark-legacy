void mainMenu() {
    int choice;
    do {
        printf("\n--- Main Menu ---\n");
        printf("1. Start Race\n");
        printf("2. View Statistics\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                startRace();
                break;
            case 2:
                displayStatistics();
                break;
            case 3:
                printf("Exiting game. Goodbye!\n");
                saveStatistics();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (! (3 == choice));
}