void view_budget() {
    printf("Budget: %.2f\n", event_budget);
    printf("Expenses: %.2f\n", expenses);
    printf("Remaining: %.2f\n", event_budget - expenses);
}