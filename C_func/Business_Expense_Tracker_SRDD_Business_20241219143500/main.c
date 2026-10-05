int main() {
    int choice;
    printf("Welcome to the Business Expense Tracker!\n");
    while (1) {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                listExpenses();
                break;
            case 3:
                filterExpensesByCategory();
                break;
            case 4:
                generateReport();
                break;
            case 5:
                deleteExpense();
                break;
            case 6:
                analyzeTrends();
                break;
            case 0:
                exitProgram();
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}