void calculateMovingAverage(int windowSize) {
    printf("Calculating moving average with window size %d...\n", windowSize);
    for (int col = 0; col < numColumns; col++) {
        printf("Column %d:\n", col + 1);
        for (int i = 0; i < numRows - windowSize + 1; i++) {
            double sum = 0.0;
            for (int j = 0; j < windowSize; j++) {
                sum += dataset[i + j][col];
            }
            printf("Moving average at row %d: %.2f\n", i + 1, sum / windowSize);
        }
    }
}