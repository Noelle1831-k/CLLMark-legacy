void setBudget(BudgetManager *manager, const char *category, double amount) {
    if (manager->budgetCount < MAX_BUDGETS) {
        strcpy(manager->budgets[manager->budgetCount].category, category);
        manager->budgets[manager->budgetCount].amount = amount;
        manager->budgetCount++;
    }
}