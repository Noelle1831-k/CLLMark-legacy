void generateInsights(IncomeTracker *incomeTracker, ExpenseTracker *expenseTracker, BudgetGoal *budgetGoal) {
    double savings = incomeTracker->totalIncome - expenseTracker->totalExpense;
    printf("Generating insights...\n");
    printf("Current Savings: $%.2lf\n", savings);
    if (savings < budgetGoal->targetSavings) {
        printf("You need to save $%.2lf more to reach your savings goal.\n", budgetGoal->targetSavings - savings);
    } else {
        printf("Congratulations! You have reached your savings goal.\n");
    }
    for (int i = 0; i < expenseTracker->expenseCount; i++) {
        if (expenseTracker->expenses[i].amount > (incomeTracker->totalIncome * 0.2)) {
            printf("Warning: High spending detected in category '%s'. Consider reducing expenses.\n", expenseTracker->expenses[i].category);
        }
    }
}