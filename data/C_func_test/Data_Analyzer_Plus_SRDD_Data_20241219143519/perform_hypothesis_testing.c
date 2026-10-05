void perform_hypothesis_testing(double *data, int size) {
    printf("Hypothesis Testing:\n");
    printf("One-Sample t-Test:\n");
    double mean = 0, variance = 0;
    for (int i = 0; i < size; i++) {
        mean += data[i];
    }
    mean /= size;
    for (int i = 0; i < size; i++) {
        variance += (data[i] - mean) * (data[i] - mean);
    }
    variance /= size;
    double t_statistic = mean / sqrt(variance / size);
    printf("t-statistic: %.2f\n", t_statistic);
}