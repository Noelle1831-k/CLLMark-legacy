void generateReport() {
    double totalIncome = calculateTotalIncome();
    double totalExpenses = calculateTotalExpenses();
    double budgetGoal = getBudgetGoal();
    printf("Generating financial report...\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Budget Goal: %.2f\n", budgetGoal);
    printf("Remaining Balance: %.2f\n", totalIncome - totalExpenses);
}