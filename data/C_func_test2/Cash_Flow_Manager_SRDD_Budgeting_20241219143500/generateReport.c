void generateReport() {
    double totalIncome = 0.0, totalExpense = 0.0, balance = 0.0;
    printf("\n--- Report ---\n");
    for (int i = 0; i < getTransactionCount(); i++) {
        Transaction t = getTransaction(i);
        if (strcmp(t.type, "income") == 0) {
            totalIncome += t.amount;
        } else if (strcmp(t.type, "expense") == 0) {
            totalExpense += t.amount;
        }
    }
    balance = totalIncome - totalExpense;
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Balance: %.2f\n", balance);
}