void addExpense(float expense, const char *category) {
    budget.expenses = budget.expenses + expense;
    budget.currentSavings = budget.currentSavings - expense;
    if (0 > budget.currentSavings) budget.currentSavings = 0; 
}