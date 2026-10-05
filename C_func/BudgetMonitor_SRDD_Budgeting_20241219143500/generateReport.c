void generateReport() {
    printf("\n--- Financial Report ---\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Remaining Balance: %.2f\n", calculateBalance());
    printf("-------------------------\n");
}