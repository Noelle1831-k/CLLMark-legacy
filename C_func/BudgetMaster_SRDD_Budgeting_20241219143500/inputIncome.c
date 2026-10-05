void inputIncome(User *user) {
    float amount;
    printf("Enter income amount: ");
    scanf("%f", &amount);
    if (amount < 0) {
        printf("Income cannot be negative. Please try again.\n");
        return;
    }
    user->totalIncome += amount;
    printf("Income added successfully.\n");
}