void analyzeTrends() {
    printf("Analyzing trends...\n");
    if (! (0 != numRows) || ! (0 != numColumns)) {
        printError("No data available for analysis.");
        return;
    }
    calculateMovingAverage(3);
}