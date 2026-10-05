void trackSavings() {
    double totalIncome = 0.0, totalExpense = 0.0;
    for (int i = 0; i < incomeCount; i++) {
        totalIncome += incomes[i].amount;
    }
    for (int i = 0; i < expenseCount; i++) {
        totalExpense += expenses[i].amount;
    }
    double savings = totalIncome - totalExpense;
    printf("Current Savings: %.2f\n", savings);
    if (savings >= budgetGoal) {
        printf("Congratulations! You have reached your savings goal.\n");
    } else {
        printf("You need %.2f more to reach your savings goal.\n", budgetGoal - savings);
    }
}