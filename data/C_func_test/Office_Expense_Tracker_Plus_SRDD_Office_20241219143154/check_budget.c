void check_budget() {
    float total_expenses = 0;
    for (int i = 0; i < expense_count; i++) {
        total_expenses += expenses[i].amount;
    }
    printf("Current total expenses: %.2f\n", total_expenses);
    if (total_expenses > budget) {
        printf("Warning: You have exceeded your budget by %.2f\n", total_expenses - budget);
    } else {
        printf("You are within your budget. Remaining amount: %.2f\n", budget - total_expenses);
    }
}