void add_expense() {
    double expense;
    printf("Enter the expense amount: ");
    scanf("%lf", &expense);
    expenses += expense;
    if (expenses > event_budget) {
        printf("Warning: You have exceeded the budget!\n");
    } else {
        printf("Expense added successfully.\n");
    }
}