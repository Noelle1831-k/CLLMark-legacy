float calculateBalance() {
    float totalExpenses = 0;
    for (int i = 0; i < expenseCount; i++) {
        totalExpenses += expenses[i].amount;
    }
    return totalIncome - totalExpenses;
}