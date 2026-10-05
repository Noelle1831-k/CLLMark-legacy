int main() {
    initializeExpenseManager();
    initializeBudgetManager();
    int choice;
    while (1) {
        printf("Welcome to Financial Expense Analyzer\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Set Budget\n");
        printf("4. Generate Report\n");
        printf("5. Get Recommendations\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                setBudget();
                break;
            case 4:
                generateReport();
                break;
            case 5:
                getRecommendations();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}