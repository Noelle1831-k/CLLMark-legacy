int generateVisualizations(Metrics *metrics) {
    if (metrics == NULL) {
        fprintf(stderr, "Error: Null metrics reference passed to generateVisualizations.\n");
        return 0;
    }
    printf("Generating visualizations...\n");
    printf("Average Review Time: %.2f\n", metrics->averageReviewTime);
    printf("Code Coverage: %.2f%%\n", metrics->codeCoverage);
    return 1;
}