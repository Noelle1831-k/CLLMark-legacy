void checkBudget() {
    double totalExpenses = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        totalExpenses += expenses[i].amount;
    }
    if (totalExpenses > budget) {
        printf("Warning: You have exceeded your budget!\n");
    } else {
        printf("You are within your budget.\n");
    }
}