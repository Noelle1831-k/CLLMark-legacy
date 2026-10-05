void handleUserInput() {
    printf("Handling user input...\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Starting Single Player mode...\n");
            currentMode = 1;
            break;
        case 2:
            printf("Starting Multiplayer mode...\n");
            currentMode = 2;
            break;
        case 3:
            printf("Starting Time Trials mode...\n");
            currentMode = 3;
            break;
        case 4:
            printf("Exiting game...\n");
            currentMode = 0;
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
}