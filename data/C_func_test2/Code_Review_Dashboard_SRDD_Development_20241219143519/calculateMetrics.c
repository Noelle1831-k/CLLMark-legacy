int calculateMetrics(AggregatedData *data, Metrics *metrics) {
    if (data == NULL || metrics == NULL) {
        fprintf(stderr, "Error: Null reference passed to calculateMetrics.\n");
        return 0;
    }
    printf("Calculating metrics...\n");
    metrics->averageReviewTime = (double)data->totalReviews / (data->openReviews + 1); 
    metrics->codeCoverage = 75.0; 
    return 1;
}