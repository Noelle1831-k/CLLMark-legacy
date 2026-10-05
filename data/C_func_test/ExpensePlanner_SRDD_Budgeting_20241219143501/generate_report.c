void generate_report() {
    printf("=== Financial Report ===\n");
    float total_expenses = calculate_total_expenses();
    float remaining_budget = get_budget() - total_expenses;
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Remaining Budget: $%.2f\n", remaining_budget);
    if (remaining_budget < 0) {
        printf("Warning: You have exceeded your budget by $%.2f.\n", -remaining_budget);
    } else {
        printf("You are within your budget. Keep it up!\n");
    }
}