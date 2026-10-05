void add_income() {
    float amount;
    printf("Enter income amount: ");
    scanf("%f", &amount);
    current_user.income += amount;
    printf("Income added successfully. Total income: %.2f\n", current_user.income);
}