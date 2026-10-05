Expense *create_expense(float amount, char *category, int date) {
    Expense *expense = (Expense *)malloc(sizeof(Expense));
    expense->amount = amount;
    strcpy(expense->category, category);
    expense->date = date;
    printf("Expense created: Amount = %.2f, Category = %s, Date = %d\n", amount, category, date);
    return expense;
}