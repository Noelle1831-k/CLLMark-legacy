void buildPredictiveModel() {
    printf("Building predictive model...\n");
    if (numRows == 0 || numColumns == 0) {
        printError("No data available for modeling.");
        return;
    }
    linearRegression();
}