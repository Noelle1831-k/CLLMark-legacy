void calculate_correlation() {
    printf("Calculating correlation coefficients...\n");
    if (!pearson_correlation() || !spearman_correlation() || !kendall_correlation()) {
        fprintf(stderr, "Error: Correlation calculation failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("Correlation coefficients calculated successfully.\n");
}