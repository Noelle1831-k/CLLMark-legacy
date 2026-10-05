void analyze_trends(double *data, int size) {
    printf("Trend Analysis:\n");
    printf("Moving Average:\n");
    int window = 3;
    for (int i = 0; i <= size - window; i++) {
        double sum = 0;
        for (int j = 0; j < window; j++) {
            sum += data[i + j];
        }
        printf("Window %d: %.2f\n", i + 1, sum / window);
    }
    printf("\nExponential Smoothing:\n");
    printf("Feature to be implemented in future versions.\n");
}