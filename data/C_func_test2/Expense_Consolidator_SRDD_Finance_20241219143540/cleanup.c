void cleanup(ExpenseConsolidator *app) {
    for (int i = 0; i < app->account_count; i++) {
        free(app->accounts[i]);
    }
    free(app->accounts);
    for (int i = 0; i < app->expense_count; i++) {
        free(app->expenses[i]);
    }
    free(app->expenses);
    free(app->dashboard->expenses);
    free(app->dashboard);
    printf("Memory cleaned up. Application shutting down.\n");
}