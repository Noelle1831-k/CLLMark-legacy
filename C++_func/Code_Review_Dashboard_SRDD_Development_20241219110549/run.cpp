void Dashboard::run() {
    cout << "Running Dashboard..." << endl;
    dataAggregator.fetchData();
    metricsCalculator.calculateMetrics();
    visualization.createVisuals();
}