void inputExpense() {
    float expense;
    char category[50];
    printf("Enter your expense amount: ");
    scanf("%f", &expense);
    printf("Enter expense category: ");
    scanf("%s", category);
    if (expense < 0) {
        printf("Expense cannot be negative. Please try again.\n");
        return;
    }
    addExpense(expense, category);
    printf("Expense of %.2f in category '%s' added successfully!\n", expense, category);
}