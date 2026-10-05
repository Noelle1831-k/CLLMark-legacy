void generateBudgetReport() {
    printf("Generating budget report...\n");
    for (int i = 0; i < budgetCount; i++) {
        printf("%s: Limit %.2f, Spent %.2f\n", budgets[i].category, budgets[i].limit, budgets[i].spent);
    }
}