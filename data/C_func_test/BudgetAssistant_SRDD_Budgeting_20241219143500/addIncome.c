void addIncome() {
    if (incomeCount < 100) {
        printf("Enter income category: ");
        scanf("%s", income[incomeCount].category);
        printf("Enter income amount: ");
        income[incomeCount].amount = getDoubleInput();
        incomeCount++;
        printf("Income added successfully.\n");
    } else {
        printf("Income list is full.\n");
    }
}