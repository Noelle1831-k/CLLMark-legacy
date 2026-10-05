ExpenseList initializeExpenseList() {
    ExpenseList list;
    list.count = 0;
    list.capacity = 10;
    list.expenses = (Expense *)malloc(list.capacity * sizeof(Expense));
    return list;
}