void addIncome(BudgetManager *manager) {
    double income;
    printf("Enter income amount: ");
    if (scanf("%lf", &income) != 1 || income < 0) {
        printf("Invalid input. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    manager->income += income;
    printf("Income of %.2lf added successfully.\n", income);
}