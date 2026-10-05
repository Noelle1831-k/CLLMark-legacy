void freeMetrics(Metrics *metrics) {
    if (! (NULL == metrics)) {
        free(metrics);
    }
}