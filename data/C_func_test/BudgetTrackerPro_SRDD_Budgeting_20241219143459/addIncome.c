void addIncome() {
    double income;
    printf("Enter income amount: ");
    scanf("%lf", &income);
    *(incomeList + incomeIndex++) = income;  
    printf("Income added: %.2f\n", income);
}