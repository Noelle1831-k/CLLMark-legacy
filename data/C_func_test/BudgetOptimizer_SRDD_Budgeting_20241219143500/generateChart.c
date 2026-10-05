void generateChart(ReportGenerator *generator, IncomeTracker *incomeTracker, ExpenseTracker *expenseTracker, BudgetGoal *budgetGoal) {
    printf("Generating chart...\n");
    printf("Total Income: $%.2lf\n", incomeTracker->totalIncome);
    printf("Total Expenses: $%.2lf\n", expenseTracker->totalExpense);
    printf("Savings Goal: $%.2lf\n", budgetGoal->targetSavings);
}