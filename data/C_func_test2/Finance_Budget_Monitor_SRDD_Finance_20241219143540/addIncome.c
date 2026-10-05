void addIncome() {
    Transaction newIncome;
    printf("Enter income amount: ");
    newIncome.amount = getValidatedDoubleInput();
    printf("Enter income category: ");
    getValidatedStringInput(newIncome.category, 50);
    printf("Enter income description: ");
    getValidatedStringInput(newIncome.description, 100);
    *(incomeList + incomeCount++) = newIncome;
    printf("Income added successfully: %.2f (Category: %s, Description: %s)\n", 
           newIncome.amount, newIncome.category, newIncome.description);
}