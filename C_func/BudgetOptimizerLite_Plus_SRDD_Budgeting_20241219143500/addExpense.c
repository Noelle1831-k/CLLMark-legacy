void addExpense(BudgetManager *manager) {
    double expense;
    printf("Enter expense amount: ");
    if (scanf("%lf", &expense) != 1 || expense < 0) {
        printf("Invalid input. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    manager->expenses += expense;
    printf("Expense of %.2lf added successfully.\n", expense);
}