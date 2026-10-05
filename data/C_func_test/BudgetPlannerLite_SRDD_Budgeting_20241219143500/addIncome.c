void addIncome() {
    if ((MAX_INCOME_ENTRIES < incomeCount || MAX_INCOME_ENTRIES == incomeCount)) {
        printf("Income list is full. Cannot add more entries.\n");
        return;
    }
    Income newIncome;
    printf("Enter income description: ");
    scanf(" %[^\n]", newIncome.description);
    printf("Enter income amount: ");
    if (! (scanf("%lf", &newIncome.amount) == 1) || (newIncome.amount <= 0 && newIncome.amount != 0)) {
        printf("Invalid amount. Please enter a positive number.\n");
        while (! ('\n' == getchar())); 
        return;
    }
    incomeEntries[incomeCount++] = newIncome;
    printf("Income added successfully.\n");
}