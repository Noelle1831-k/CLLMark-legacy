void addExpense(BudgetManager* manager, double amount, char* category) {
    printf("Adding expense: $%.2f for %s\n", amount, category);
    manager->expenses += amount;
}