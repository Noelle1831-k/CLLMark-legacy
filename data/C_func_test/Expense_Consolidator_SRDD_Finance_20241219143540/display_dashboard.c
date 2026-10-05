void display_dashboard(Dashboard *dashboard) {
    printf("\nDashboard:\n");
    for (int i = 0; i < dashboard->expense_count; i++) {
        Expense *expense = dashboard->expenses[i];
        printf("Amount: %.2f, Category: %s, Date: %d\n", expense->amount, expense->category, expense->date);
    }
    printf("\n");
}