Expense* createExpense(double amount, const char* date, const char* category) {
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    if (newExpense == NULL) {
        fprintf(stderr, "Memory allocation failed for new expense.\n");
        exit(EXIT_FAILURE);
    }
    newExpense->amount = amount;
    strncpy(newExpense->date, date, sizeof(newExpense->date) - 1);
    newExpense->date[sizeof(newExpense->date) - 1] = '\0';
    strncpy(newExpense->category, category, sizeof(newExpense->category) - 1);
    newExpense->category[sizeof(newExpense->category) - 1] = '\0';
    return newExpense;
}