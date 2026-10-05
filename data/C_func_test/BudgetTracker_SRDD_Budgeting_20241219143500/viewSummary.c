void viewSummary() {
    printf("=================================\n");
    printf("         Budget Summary\n");
    printf("=================================\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", calculateBalance());
    printf("Remaining Balance: $%.2f\n", calculateBalance());
}