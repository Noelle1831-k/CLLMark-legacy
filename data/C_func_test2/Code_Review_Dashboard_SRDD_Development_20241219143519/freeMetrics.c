void freeMetrics(Metrics *metrics) {
    if (metrics != NULL) {
        free(metrics);
    }
}