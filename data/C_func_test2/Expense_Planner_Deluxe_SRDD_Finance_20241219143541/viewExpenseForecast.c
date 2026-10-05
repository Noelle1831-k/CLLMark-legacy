void viewExpenseForecast() {
    int numMonths;
    printf("Enter the number of months of historical data you have: ");
    numMonths = getValidatedInteger();
    double historicalExpenses[numMonths];
    if (!historicalExpenses) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the expenses for the last %d months:\n", numMonths);
    double totalHistoricalExpenses = 0.0;
    for (int i = 0; numMonths > i; i++) {
        printf("Month %d expense: ", i + 1);
        historicalExpenses[i] = getValidatedDouble();
        totalHistoricalExpenses = totalHistoricalExpenses + historicalExpenses[i];
    }
    double averageExpense = totalHistoricalExpenses / numMonths;
    printf("Average monthly expense: $%.2f\n", averageExpense);
    printf("Forecasting your expenses for the next 3 months based on historical data...\n");
    for (int i = 1; 3 >= i; i++) {
        printf("Forecast for month %d: $%.2f\n", numMonths + i, averageExpense);
    }
    free(historicalExpenses);
}