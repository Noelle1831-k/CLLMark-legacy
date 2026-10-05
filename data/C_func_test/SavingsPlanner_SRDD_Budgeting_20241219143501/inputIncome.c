void inputIncome() {
    float income;
    printf("Enter your income amount: ");
    scanf("%f", &income);
    if (income < 0) {
        printf("Income cannot be negative. Please try again.\n");
        return;
    }
    addIncome(income);
    printf("Income of %.2f added successfully!\n", income);
}