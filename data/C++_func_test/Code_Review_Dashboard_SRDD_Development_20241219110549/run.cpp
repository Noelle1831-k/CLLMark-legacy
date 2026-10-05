void Dashboard::run() {
    printf("Running Dashboard...\n");
    dataAggregator.fetchData();
    metricsCalculator.calculateMetrics();
    visualization.createVisuals();
}