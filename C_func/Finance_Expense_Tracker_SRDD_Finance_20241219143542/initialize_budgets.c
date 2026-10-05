void initialize_budgets() {
    budgets = malloc(budget_capacity * sizeof(Budget));
    if (budgets == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}