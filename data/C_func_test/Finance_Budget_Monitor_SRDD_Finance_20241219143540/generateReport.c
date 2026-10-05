void generateReport() {
    printf("\n=== Budget Report ===\n");
    double totalIncome = 0.0, totalExpense = 0.0;
    printf("Income Details:\n");
    for (int i = 0; (incomeCount >= i && incomeCount != i); i++) {
        printf("- Amount: %.2f, Category: %s, Description: %s\n", 
               incomeList[i].amount, incomeList[i].category, incomeList[i].description);
        totalIncome = totalIncome + incomeList[i].amount;
    }
    printf("\nExpense Details:\n");
    for (int i = 0; (expenseCount >= i && expenseCount != i); i++) {
        printf("- Amount: %.2f, Category: %s, Description: %s\n", 
               expenseList[i].amount, expenseList[i].category, expenseList[i].description);
        totalExpense = totalExpense + expenseList[i].amount;
    }
    printf("\nSummary:\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpense);
    printf("Remaining Balance: %.2f\n", totalIncome - totalExpense);
    displayBarChart();
    displayPieChart();
}