Expense* createExpense(double amount, const char *category, const char *description) {
    Expense *expense = (Expense*)malloc(sizeof(Expense));
    expense->amount = amount;
    strncpy(expense->category, category, sizeof(expense->category) - 1);
    strncpy(expense->description, description, sizeof(expense->description) - 1);
    return expense;
}