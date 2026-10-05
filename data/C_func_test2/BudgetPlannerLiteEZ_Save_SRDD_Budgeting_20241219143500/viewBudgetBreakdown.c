void viewBudgetBreakdown() {
    double totalIncome = 0.0, totalExpense = 0.0;
    for (int i = 0; i < incomeCount; i++) {
        totalIncome += incomes[i].amount;
    }
    for (int i = 0; i < expenseCount; i++) {
        totalExpense += expenses[i].amount;
    }
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpense);
    printf("Remaining Budget: %.2f\n", totalIncome - totalExpense);
    printf("Budget Goal: %.2f\n", budgetGoal);
}