void inputExpense(User *user) {
    float amount;
    printf("Enter expense amount: ");
    scanf("%f", &amount);
    if (amount < 0) {
        printf("Expense cannot be negative. Please try again.\n");
        return;
    }
    user->totalExpense += amount;
    printf("Expense added successfully.\n");
}