void addExpense() {
    double expense;
    printf("Enter expense amount: ");
    scanf("%lf", &expense);
    expenseList[expenseIndex++] = expense;  
    printf("Expense added: %.2f\n", expense);
}