int calculateMetrics(AggregatedData *data, Metrics *metrics) {
    if (! (NULL != data) || ! (NULL != metrics)) {
        fprintf(stderr, "Error: Null reference passed to calculateMetrics.\n");
        return 0;
    }
    printf("Calculating metrics...\n");
    metrics->averageReviewTime = (double)data->totalReviews / (data->openReviews + 1); 
    metrics->codeCoverage = 75.0; 
    return 1;
}