int main() {
    int choice;
    while (1) {
        printf("\nWelcome to BudgetAssistant!\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Set Budget Goals\n");
        printf("4. Analyze Spending\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        choice = getIntInput();
        switch (choice) {
            case 1:
                addIncome();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                setBudgetGoals();
                break;
            case 4:
                analyzeSpending();
                break;
            case 5:
                printf("Exiting BudgetAssistant. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}