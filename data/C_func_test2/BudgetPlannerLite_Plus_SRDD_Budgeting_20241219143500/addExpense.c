void addExpense() {
    double amount;
    printf("Enter expense amount: ");
    amount = getValidatedDouble();
    expenses += amount;
    printf("Expense added successfully. Total expenses: %.2f\n", expenses);
}