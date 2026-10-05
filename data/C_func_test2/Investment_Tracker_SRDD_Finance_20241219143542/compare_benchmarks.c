void compare_benchmarks(Portfolio *portfolio) {
    double benchmark = 1500;  
    double total = get_total_value(portfolio);
    printf("Portfolio value: %f, Benchmark: %f\n", total, benchmark);
    printf("Performance is %s benchmark.\n", total >= benchmark ? "above" : "below");
}