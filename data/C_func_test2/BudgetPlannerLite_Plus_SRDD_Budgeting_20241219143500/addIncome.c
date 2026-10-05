void addIncome() {
    double amount;
    printf("Enter income amount: ");
    amount = getValidatedDouble();
    income = income + amount;
    printf("Income added successfully. Total income: %.2f\n", income);
}