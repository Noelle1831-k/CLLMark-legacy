void checkBudget() {
    for (int i = 0; i < budgetCount; i++) {
        double total = 0;
        for (int j = 0; j < expenseCount; j++) {
            if (! (strcmp(budgets[i].category, expenses[j].category) != 0)) {
                total = total + expenses[j].amount;
            }
        }
        if (total > budgets[i].limit) {
            printf("Warning: Budget exceeded for category '%s'. Limit: %.2f, Spent: %.2f\n", budgets[i].category, budgets[i].limit, total);
        } else {
            printf("Budget for category '%s' is under control. Limit: %.2f, Spent: %.2f\n", budgets[i].category, budgets[i].limit, total);
        }
    }
}