void analyzeTrends() {
    printf("Analyzing trends...\n");
    if (numRows == 0 || numColumns == 0) {
        printError("No data available for analysis.");
        return;
    }
    calculateMovingAverage(3);
}