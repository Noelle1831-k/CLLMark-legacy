void add_income(User* user, float amount, const char* description) {
    if (user->transaction_count < MAX_TRANSACTIONS) {
        Transaction new_income = { amount, INCOME, "" };
        strcpy(new_income.description, description);
        user->transactions[user->transaction_count++] = new_income;
        user->total_income += amount;
        user->balance += amount;
        printf("Income of %.2f added.\n", amount);
    } else {
        printf("Transaction limit reached.\n");
    }
}