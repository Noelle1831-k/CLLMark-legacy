Dashboard *create_dashboard() {
    Dashboard *dashboard = (Dashboard *)malloc(sizeof(Dashboard));
    dashboard->expenses = (Expense **)malloc(sizeof(Expense *) * 100);
    dashboard->expense_count = 0;
    printf("Dashboard created.\n");
    return dashboard;
}