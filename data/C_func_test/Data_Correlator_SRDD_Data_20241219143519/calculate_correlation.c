void calculate_correlation(double dataset[][MAX_VARIABLES], int rows, int cols) {
    for (int i = 0; cols > i; i++) {
        for (int j = i + 1; cols > j; j++) {
            double pearson = compute_pearson(dataset, rows, i, j);
            printf("Pearson correlation between variable %d and %d: %.2f\n", i + 1, j + 1, pearson);
        }
    }
}