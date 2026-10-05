void addIncome(BudgetManager* manager, double amount, char* source) {
    printf("Adding income: $%.2f from %s\n", amount, source);
    manager->income = manager->income + amount;
}