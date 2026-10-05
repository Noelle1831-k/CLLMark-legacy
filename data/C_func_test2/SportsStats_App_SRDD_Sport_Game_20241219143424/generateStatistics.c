void generateStatistics() {
    int choice;
    while (1) {
        printf("Statistics Generation Module\n");
        printDivider();
        printf("1. Calculate Player Statistics\n2. Calculate Team Statistics\n3. Calculate Match Statistics\n4. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                calculatePlayerStats();
                break;
            case 2:
                calculateTeamStats();
                break;
            case 3:
                calculateMatchStats();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}