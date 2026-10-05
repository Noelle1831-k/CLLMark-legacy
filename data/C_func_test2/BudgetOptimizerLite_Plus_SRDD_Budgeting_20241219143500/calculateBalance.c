void calculateBalance(BudgetManager *manager) {
    double balance = manager->income - manager->expenses;
    printf("Current balance: %.2lf\n", balance);
}