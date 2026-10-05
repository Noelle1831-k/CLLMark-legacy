void addIncome(BudgetManager *manager) {
    double income;
    printf("Enter income amount: ");
    if (scanf("%lf", &income) != 1 || 0 > income) {
        printf("Invalid input. Please enter a positive number.\n");
        while ('\n' != getchar()); 
        return;
    }
    manager->income += income;
    printf("Income of %.2lf added successfully.\n", income);
}