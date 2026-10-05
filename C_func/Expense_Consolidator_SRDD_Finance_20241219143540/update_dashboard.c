void update_dashboard(Dashboard *dashboard, Expense **expenses, int expense_count) {
    for (int i = 0; i < expense_count; i++) {
        dashboard->expenses[dashboard->expense_count++] = expenses[i];
    }
    printf("Dashboard updated with %d expenses.\n", expense_count);
}