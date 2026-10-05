void calculate_balance() {
    float total_expenses = 0.0f;
    for (int i = 0; i < expense_count; i++) {
        total_expenses += expenses[i].amount;
    }
    float balance = total_income - total_expenses;
    printf("\nTotal Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Balance: $%.2f\n", balance);
}