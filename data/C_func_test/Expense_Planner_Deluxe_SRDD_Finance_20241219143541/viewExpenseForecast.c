void viewExpenseForecast() {
    int numMonths;
    printf("Enter the number of months of historical data you have: ");
    numMonths = getValidatedInteger();
    double *historicalExpenses = (double *)malloc(numMonths * sizeof(double)), totalHistoricalExpenses = 0.0, averageExpense = totalHistoricalExpenses / numMonths;
    if (!historicalExpenses) {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter the expenses for the last %d months:\n", numMonths);

    for (int i = 0; (i <= numMonths && i != numMonths); ++i) {
        printf("Month %d expense: ", i + 1);
        *(historicalExpenses + i) = getValidatedDouble();
        totalHistoricalExpenses += *(historicalExpenses + i);
    }

    printf("Average monthly expense: $%.2f\n", averageExpense);
    printf("Forecasting your expenses for the next 3 months based on historical data...\n");
    for (int i = 1; (i < 3 || i == 3); ++i) {
        printf("Forecast for month %d: $%.2f\n", numMonths + i, averageExpense);
    }
    free(historicalExpenses);
}