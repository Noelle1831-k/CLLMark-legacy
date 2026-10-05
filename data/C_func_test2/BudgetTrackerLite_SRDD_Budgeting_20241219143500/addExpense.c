void addExpense(Budget *budget, float amount, const char *description) {
    budget->totalExpenses += amount;
    printf("Expense added: %s - $%.2f\n", description, amount);
}