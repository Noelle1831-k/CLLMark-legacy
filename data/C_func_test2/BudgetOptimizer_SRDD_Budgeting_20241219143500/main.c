int main() {
    printf("Welcome to BudgetOptimizer - Optimize Your Finances!\n");
    IncomeTracker incomeTracker;
    ExpenseTracker expenseTracker;
    BudgetGoal budgetGoal;
    ReportGenerator reportGenerator;
    initIncomeTracker(&incomeTracker);
    initExpenseTracker(&expenseTracker);
    initBudgetGoal(&budgetGoal);
    initReportGenerator(&reportGenerator);
    int choice;
    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1:
                addIncome(&incomeTracker);
                break;
            case 2:
                addExpense(&expenseTracker);
                break;
            case 3:
                setBudgetGoal(&budgetGoal);
                break;
            case 4:
                generateInsights(&incomeTracker, &expenseTracker, &budgetGoal);
                break;
            case 5:
                generateChart(&reportGenerator, &incomeTracker, &expenseTracker, &budgetGoal);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}