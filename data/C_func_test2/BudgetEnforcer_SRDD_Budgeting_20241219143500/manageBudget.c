void manageBudget() {
    int choice;
    while (1) {
        printf("\nBudget Management:\n");
        printf("1. Add Category\n");
        printf("2. View Budget\n");
        printf("3. Record Expense\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            handleError("Invalid input. Please enter a number.");
        }
        switch (choice) {
            case 1:
                addBudgetCategory();
                break;
            case 2:
                viewBudget();
                break;
            case 3:
                recordExpense();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}