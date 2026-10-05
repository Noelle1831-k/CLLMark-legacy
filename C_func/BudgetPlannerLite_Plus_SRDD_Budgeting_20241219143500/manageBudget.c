void manageBudget() {
    int choice;
    while (1) {
        printf("\n=== Manage Budget ===\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Current Budget\n");
        printf("4. Return to Main Menu\n");
        printf("Enter your choice: ");
        choice = getValidatedInput(1, 4);
        switch (choice) {
            case 1:
                addIncome();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                viewBudget();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Returning to main menu.\n");
        }
    }
}