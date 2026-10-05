void add_expense(User* user, float amount, const char* description) {
    if (user->transaction_count < MAX_TRANSACTIONS) {
        Transaction new_expense = { amount, EXPENSE, "" };
        strcpy(new_expense.description, description);
        user->transactions[user->transaction_count++] = new_expense;
        user->total_expenses += amount;
        user->balance -= amount;
        printf("Expense of %.2f added.\n", amount);
    } else {
        printf("Transaction limit reached.\n");
    }
}