Expense **fetch_expenses(Account *account) {
    Expense **expenses = (Expense **)malloc(sizeof(Expense *) * 10);
    for (int i = 0; i < 10; i++) {
        expenses[i] = (Expense *)malloc(sizeof(Expense));
        expenses[i]->amount = (rand() % 150) + 1;
        strcpy(expenses[i]->category, "Uncategorized");
        expenses[i]->date = rand() % 30 + 1;
    }
    printf("Expenses fetched for account: %s\n", account->account_type);
    return expenses;
}