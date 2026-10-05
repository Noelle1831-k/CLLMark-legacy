void mainMenu() {
    int choice;
    while (1) {
        printf("\n===== TEAM MANAGER =====\n");
        printf("1. Manage Team\n");
        printf("2. Recruit Players\n");
        printf("3. Train Players\n");
        printf("4. Strategy and Tactics\n");
        printf("5. Simulate Match\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                manageTeam();
                break;
            case 2:
                recruitPlayers();
                break;
            case 3:
                trainPlayers();
                break;
            case 4:
                setTactics();
                break;
            case 5:
                simulateMatch();
                break;
            case 6:
                printf("Exiting the game. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}