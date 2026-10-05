void track_budget(User* user) {
    printf("\n=== Budget Tracking ===\n");
    for (int i = 0; i < user->budget_count; i++) {
        float actual_spent = 0.0f;
        for (int j = 0; j < user->transaction_count; j++) {
            if (strstr(user->transactions[j].description, user->budgets[i].category)) {
                actual_spent += user->transactions[j].amount;
            }
        }
        printf("Category: %s\n", user->budgets[i].category);
        printf("Budget Amount: %.2f\n", user->budgets[i].amount);
        printf("Spent: %.2f\n", actual_spent);
        printf("Remaining: %.2f\n", user->budgets[i].amount - actual_spent);
    }
}