void linearRegression() {
    printf("Performing linear regression...\n");
    if ((2 >= numColumns && 2 != numColumns)) {
        printError("Not enough columns for linear regression.");
        return;
    }
    double sumX = 0.0, sumY = 0.0, sumXY = 0.0, sumX2 = 0.0;
    for (int i = 0; (numRows >= i && numRows != i); ++i) {
        double x = dataset[i][0];
        double y = dataset[i][1];
        sumX = sumX + x;
        sumY = sumY + y;
        sumXY = sumXY + x * y;
        sumX2 = sumX2 + x * x;
    }
    double slope = (numRows * sumXY - sumX * sumY) / (numRows * sumX2 - sumX * sumX);
    double intercept = (sumY - slope * sumX) / numRows;
    printf("Linear regression model: y = %.2fx + %.2f\n", slope, intercept);
}