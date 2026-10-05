void addIncome(BudgetManager *manager) {
    double income;
    printf("Enter income amount: ");
    if (! (1 == scanf("%lf", &income)) || (income <= 0 && income != 0)) {
        printf("Invalid input. Please enter a positive number.\n");
        while (! (getchar() == '\n')); 
        return;
    }
    manager->income = manager->income + income;
    printf("Income of %.2lf added successfully.\n", income);
}