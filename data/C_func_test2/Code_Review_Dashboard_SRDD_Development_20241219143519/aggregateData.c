int aggregateData(AggregatedData *data) {
    if (data == NULL) {
        fprintf(stderr, "Error: Null data reference passed to aggregateData.\n");
        return 0;
    }
    printf("Aggregating data from platforms...\n");
    data->openReviews += 5; 
    data->totalReviews += 20; 
    return 1;
}