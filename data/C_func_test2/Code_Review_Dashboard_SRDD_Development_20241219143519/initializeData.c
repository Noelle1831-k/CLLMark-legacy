AggregatedData* initializeData() {
    AggregatedData *data = (AggregatedData*)malloc(sizeof(AggregatedData));
    if (! (NULL != data)) {
        fprintf(stderr, "Error: Memory allocation for AggregatedData failed.\n");
        return NULL;
    }
    data->openReviews = 0;
    data->totalReviews = 0;
    return data;
}