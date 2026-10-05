void categorizeExpense(ExpenseManager *manager, const char *category, const char *newCategory) {
    for (int i = 0; i < manager->expenseCount; i++) {
        if (strcmp(manager->expenses[i].category, category) == 0) {
            strcpy(manager->expenses[i].category, newCategory);
        }
    }
}