void perform_predictive_modeling(double *data, int size) {
    printf("Predictive Modeling:\n");
    printf("Linear Regression:\n");
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;
    for (int i = 0; i < size; i++) {
        sum_x += i;
        sum_y += data[i];
        sum_xy += i * data[i];
        sum_x2 += i * i;
    }
    double slope = (size * sum_xy - sum_x * sum_y) / (size * sum_x2 - sum_x * sum_x);
    double intercept = (sum_y - slope * sum_x) / size;
    printf("y = %.2fx + %.2f\n", slope, intercept);
    printf("\nPolynomial Regression (Degree 2):\n");
    printf("Feature to be implemented in future versions.\n");
}