bool Budget::isBudgetExceeded() const {
    return currentSpending > budgetAmount;
}