void set_budget(User* user) {
    printf("Enter budget category: ");
    char category[50];
    getchar();  
    fgets(category, sizeof(category), stdin);
    category[strcspn(category, "\n")] = 0;  
    printf("Enter budget amount for %s: ", category);
    float amount;
    if (scanf("%f", &amount) != 1) {
        printf("Invalid amount. Please try again.\n");
        while (getchar() != '\n');  
        return;
    }
    Budget new_budget = { amount, "", 0.0f };
    strcpy(new_budget.category, category);
    user->budgets[user->budget_count++] = new_budget;
    printf("Budget for %s set to %.2f\n", category, amount);
}