Metrics* initializeMetrics() {
    Metrics *metrics = (Metrics*)malloc(sizeof(Metrics));
    if (metrics == NULL) {
        fprintf(stderr, "Error: Memory allocation for Metrics failed.\n");
        return NULL;
    }
    metrics->averageReviewTime = 0.0;
    metrics->codeCoverage = 0.0;
    return metrics;
}