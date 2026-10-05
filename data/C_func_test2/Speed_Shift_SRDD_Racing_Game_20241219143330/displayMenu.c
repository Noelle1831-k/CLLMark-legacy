void displayMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Start Game\n");
    printf("2. View Track Info\n");
    printf("3. Exit\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n'); 
    switch (choice) {
        case 1:
            return;
        case 2:
            displayTrackInfo();
            displayMenu();
            break;
        case 3:
            printf("Exiting game. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            displayMenu();
    }
}