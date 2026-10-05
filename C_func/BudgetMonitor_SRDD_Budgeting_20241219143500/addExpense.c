void addExpense() {
    float expense;
    printf("Enter expense amount: ");
    if (scanf("%f", &expense) == 1 && expense > 0) {
        totalExpenses += expense;
        printf("Expense added successfully. Total Expenses: %.2f\n", totalExpenses);
    } else {
        printf("Invalid expense amount.\n");
        while (getchar() != '\n'); 
    }
}