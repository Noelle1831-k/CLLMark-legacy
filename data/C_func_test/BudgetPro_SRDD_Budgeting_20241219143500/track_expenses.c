void track_expenses() {
    float total_expenses = 0.0f;
    for (int i = 0; i < current_user.expense_count; i++) {
        total_expenses += current_user.expenses[i];
    }
    printf("Total expenses: %.2f\n", total_expenses);
    if (budget_goal > 0) {
        if (total_expenses > budget_goal) {
            printf("Warning: You have exceeded your budget goal by %.2f!\n", total_expenses - budget_goal);
        } else {
            printf("You are within your budget goal. Remaining budget: %.2f\n", budget_goal - total_expenses);
        }
    } else {
        printf("No budget goal set.\n");
    }
}