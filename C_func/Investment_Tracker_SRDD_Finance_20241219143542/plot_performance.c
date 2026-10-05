void plot_performance(Portfolio *portfolio) {
    printf("Plotting performance for %d investments...\n", portfolio->count);
    for (int i = 0; i < portfolio->count; i++) {
        printf("Investment %d: %s, Value: %f\n", i+1, get_category(portfolio->investments[i]), get_value(portfolio->investments[i]));
    }
    printf("Performance plotted successfully.\n");
}