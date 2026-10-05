double calculateRemainingBudget(const Budget b) {
    return b.income - calculateTotalExpenses(b);
}