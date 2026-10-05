void set_budget() {
    if (budget_count == budget_capacity) {
        budget_capacity *= 2; 
        budgets = realloc(budgets, budget_capacity * sizeof(Budget));
        if (budgets == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
    char category[MAX_CATEGORY_LENGTH];
    double budget;
    printf("Enter category: ");
    scanf("%s", category);
    printf("Enter budget for this category: ");
    scanf("%lf", &budget);
    Budget new_budget;
    strcpy(new_budget.category, category);
    new_budget.budget = budget;
    new_budget.spent = 0;
    budgets[budget_count++] = new_budget;
    printf("Budget set successfully!\n");
}