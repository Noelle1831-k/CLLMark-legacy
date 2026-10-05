void generate_dashboard(ExpenseConsolidator *app) {
    update_dashboard(app->dashboard, app->expenses, app->expense_count);
    display_dashboard(app->dashboard);
}