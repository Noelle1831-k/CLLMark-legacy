int main() {
    printf("Initializing Code Review Dashboard...\n");
    AggregatedData *data = initializeData();
    if (data == NULL) {
        fprintf(stderr, "Error: Failed to initialize data.\n");
        return EXIT_FAILURE;
    }
    Metrics *metrics = initializeMetrics();
    if (metrics == NULL) {
        fprintf(stderr, "Error: Failed to initialize metrics.\n");
        freeData(data);
        return EXIT_FAILURE;
    }
    if (!aggregateData(data)) {
        fprintf(stderr, "Error: Data aggregation failed.\n");
        freeData(data);
        freeMetrics(metrics);
        return EXIT_FAILURE;
    }
    if (!calculateMetrics(data, metrics)) {
        fprintf(stderr, "Error: Metric calculation failed.\n");
        freeData(data);
        freeMetrics(metrics);
        return EXIT_FAILURE;
    }
    if (!generateVisualizations(metrics)) {
        fprintf(stderr, "Error: Visualization generation failed.\n");
        freeData(data);
        freeMetrics(metrics);
        return EXIT_FAILURE;
    }
    freeData(data);
    freeMetrics(metrics);
    printf("Dashboard execution completed.\n");
    return EXIT_SUCCESS;
}