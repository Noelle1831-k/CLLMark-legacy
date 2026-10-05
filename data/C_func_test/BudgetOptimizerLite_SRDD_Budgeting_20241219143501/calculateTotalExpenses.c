double calculateTotalExpenses(const Budget b) {
    double total = 0.0;
    for (int i = 0; i < b.expenseCount; i++) {
        total += b.expenses[i].amount;
    }
    return total;
}