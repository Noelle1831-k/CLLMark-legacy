void viewReport() {
    printf("\nFinancial Summary:\n");
    printf("Total Income: %.2lf\n", summary.income);
    printf("Total Expenses: %.2lf\n", summary.expenses);
    printf("Remaining Budget: %.2lf\n", summary.budget - summary.expenses);
    generateCharts();  
}