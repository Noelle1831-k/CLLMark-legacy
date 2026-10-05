void display_budget_report() {
    printf("\n---- Budget Report ----\n");
    for (int i = 0; i < budget_count; i++) {
        printf("Category: %s, Budget: %.2f, Spent: %.2f\n", budgets[i].category, budgets[i].budget, budgets[i].spent);
    }
}