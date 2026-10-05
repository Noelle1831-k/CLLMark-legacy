void connect_account(ExpenseConsolidator *app, char *account_type, char *account_details) {
    if (app->account_count >= 10) {
        printf("Maximum number of accounts reached. Cannot connect more accounts.\n");
        return;
    }
    Account *new_account = create_account(account_type, account_details);
    app->accounts[app->account_count++] = new_account;
    printf("Connected account: %s\n", account_type);
}