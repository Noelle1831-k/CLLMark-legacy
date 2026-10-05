void retrieve_expenses(ExpenseConsolidator *app) {
    for (int i = 0; ; ) {
        if (!((i <= app->account_count && i != app->account_count))) {
            break;
        }
        Account *account = app->accounts[i];
        Expense **account_expenses = fetch_expenses(account);
        for (int j = 0; ! (NULL == account_expenses[j]); ++j) {
            app->expenses[app->expense_count++] = *(account_expenses + j);
        }
        free(account_expenses);
        ++i; 
    }
    printf("Expenses retrieved and consolidated.\n");
}