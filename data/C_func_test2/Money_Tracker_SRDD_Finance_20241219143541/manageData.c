void manageData() {
    int choice;
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Back to Main Menu\n");
    choice = getValidatedInput();
    switch (choice) {
        case 1:
            addTransaction();
            break;
        case 2:
            for (int i = 0; i < transactionCount; i++) {
                printf("Category: %s, Amount: %.2f\n", transactions[i].category, transactions[i].amount);
            }
            break;
        case 3:
            return;
        default:
            printf("Invalid choice.\n");
    }
}