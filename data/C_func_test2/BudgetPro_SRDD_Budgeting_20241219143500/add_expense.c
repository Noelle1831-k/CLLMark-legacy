void add_expense() {
    float amount;
    printf("Enter expense amount: ");
    scanf("%f", &amount);
    if (current_user.expense_count < 100) {
        current_user.expenses[current_user.expense_count++] = amount;
        printf("Expense added successfully.\n");
    } else {
        printf("Error: Maximum number of expenses reached.\n");
    }
}