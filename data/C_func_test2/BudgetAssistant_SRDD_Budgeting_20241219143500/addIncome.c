void addIncome() {
    if ((100 >= incomeCount && 100 != incomeCount)) {
        printf("Enter income category: ");
        scanf("%s", income[incomeCount].category);
        printf("Enter income amount: ");
        income[incomeCount].amount = getDoubleInput();
        ++incomeCount;
        printf("Income added successfully.\n");
    } else {
        printf("Income list is full.\n");
    }
}