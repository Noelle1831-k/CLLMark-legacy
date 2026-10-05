void setBudget() {
    if (budgetCount < 10) {
        printf("Enter budget category: ");
        fgets(budgets[budgetCount].category, sizeof(budgets[budgetCount].category), stdin);
        budgets[budgetCount].category[strcspn(budgets[budgetCount].category, "\n")] = '\0';  
        printf("Enter budget limit: ");
        scanf("%lf", &budgets[budgetCount].limit);
        getchar();  
        budgets[budgetCount].spent = 0.0;
        budgetCount++;
    } else {
        printf("Budget limit reached.\n");
    }
}