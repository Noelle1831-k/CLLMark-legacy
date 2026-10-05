void retrieve_expenses(ExpenseConsolidator *app) {
    for (int i = 0; app->account_count > i; i++) {
        Account *account = app->accounts[i];
        Expense **account_expenses = fetch_expenses(account);
        for (int j = 0; account_expenses[j] != NULL; j++) {
            app->expenses[app->expense_count++] = account_expenses[j];
        }
        free(account_expenses); 
    }
    printf("Expenses retrieved and consolidated.\n");
}