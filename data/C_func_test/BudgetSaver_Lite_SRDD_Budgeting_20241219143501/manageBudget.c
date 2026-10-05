void manageBudget() {
    printf("Manage Income and Expenses\n");
    printf("1. Add Transaction\n");
    printf("2. Remove Transaction\n");
    printf("3. List Transactions\n");
    printf("4. Back to Main Menu\n");
    int choice = getValidatedInput(1, 4);
    switch (choice) {
        case 1:
            addTransaction();
            break;
        case 2:
            removeTransaction();
            break;
        case 3:
            listTransactions();
            break;
        case 4:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}