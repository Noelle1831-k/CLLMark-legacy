double compareWithBudget(BudgetManager *manager, const char *category, double expenses) {
    for (int i = 0; i < manager->budgetCount; i++) {
        if (strcmp(manager->budgets[i].category, category) == 0) {
            return manager->budgets[i].amount - expenses;
        }
    }
    return 0.0;
}