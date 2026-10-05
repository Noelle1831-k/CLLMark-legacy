void setBudget() {
    if (budgetCount >= MAX_BUDGETS) {
        printf("Error: Maximum budget limit reached.\n");
        return;
    }
    Budget newBudget;
    printf("Enter category (max 49 chars): ");
    fgets(newBudget.category, sizeof(newBudget.category), stdin);
    newBudget.category[strcspn(newBudget.category, "\n")] = '\0'; 
    printf("Enter budget limit: ");
    if (scanf("%lf", &newBudget.limit) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n'); 
        return;
    }
    getchar(); 
    budgets[budgetCount++] = newBudget;
    printf("Budget set successfully.\n");
}