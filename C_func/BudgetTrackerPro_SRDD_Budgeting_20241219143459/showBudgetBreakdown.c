void showBudgetBreakdown() {
    printf("Displaying budget breakdown...\n");
    double totalIncome = calculateTotalIncome();
    double totalExpenses = calculateTotalExpenses();
    double budgetGoal = getBudgetGoal();  
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Budget Goal: %.2f\n", budgetGoal);
}