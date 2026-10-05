bool Budget::isBudgetExceeded() const {
    return (budgetAmount <= currentSpending && budgetAmount != currentSpending);
}