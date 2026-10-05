void addExpense(float expense, const char *category) {
    budget.expenses += expense;
    budget.currentSavings -= expense;
    if (budget.currentSavings < 0) budget.currentSavings = 0; 
}