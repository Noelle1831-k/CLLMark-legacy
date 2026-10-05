void handleUserInput() {
    int choice;
    char buffer[MAX_INPUT];
    while (1) {
        displayMenu();
        fgets(buffer, MAX_INPUT, stdin);
        choice = atoi(buffer);
        switch (choice) {
            case 1:
                addTransaction();
                break;
            case 2:
                viewTransactions();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                saveData();
                break;
            case 5:
                loadData();
                break;
            case 6:
                sortTransactions();
                break;
            case 7:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}