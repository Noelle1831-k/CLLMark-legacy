void initialize(ExpenseConsolidator *app) {
    app->accounts = (Account **)malloc(sizeof(Account *) * 10);
    app->account_count = 0;
    app->expenses = (Expense **)malloc(sizeof(Expense *) * 100);
    app->expense_count = 0;
    app->dashboard = create_dashboard();
    printf("Expense Consolidator initialized.\n");
}