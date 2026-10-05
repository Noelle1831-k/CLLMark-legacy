void checkGoals() {
    double totalIncome = calculateTotalIncome();
    double totalExpenses = calculateTotalExpenses();
    double remainingBudget = totalIncome - totalExpenses;
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Remaining Budget: $%.2f\n", remainingBudget);
    if (remainingBudget >= budgetGoal) {
        printf("Congratulations! You have met your budget goal.\n");
    } else {
        printf("You are $%.2f away from meeting your budget goal.\n", budgetGoal - remainingBudget);
    }
}