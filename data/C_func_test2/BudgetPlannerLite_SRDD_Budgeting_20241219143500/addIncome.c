void addIncome() {
    if (incomeCount >= MAX_INCOME_ENTRIES) {
        printf("Income list is full. Cannot add more entries.\n");
        return;
    }
    Income newIncome;
    printf("Enter income description: ");
    scanf(" %[^\n]", newIncome.description);
    printf("Enter income amount: ");
    if (1 != scanf("%lf", &newIncome.amount) || 0 > newIncome.amount) {
        printf("Invalid amount. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    *(incomeEntries + incomeCount++) = newIncome;
    printf("Income added successfully.\n");
}