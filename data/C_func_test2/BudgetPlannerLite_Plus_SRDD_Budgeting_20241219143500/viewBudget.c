void viewBudget() {
    printf("\n=== Current Budget ===\n");
    printf("Total Income: %.2f\n", income);
    printf("Total Expenses: %.2f\n", expenses);
    printf("Remaining Balance: %.2f\n", income - expenses);
}