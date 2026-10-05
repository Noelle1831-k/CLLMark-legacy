void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    Expense new_expense;
    printf("Enter expense name: ");
    read_line(new_expense.name, MAX_NAME_LENGTH);
    new_expense.amount = get_float_input("Enter expense amount: ");
    expenses[expense_count++] = new_expense;
    printf("Expense added successfully!\n");
}