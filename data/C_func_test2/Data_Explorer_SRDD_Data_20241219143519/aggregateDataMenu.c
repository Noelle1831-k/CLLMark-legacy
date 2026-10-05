void aggregateDataMenu(Data *data) {
    printf("\nSelect aggregation operation:\n");
    printf("1. Sum\n");
    printf("2. Average\n");
    printf("Enter your choice: ");
    int aggChoice;
    scanf("%d", &aggChoice);
    aggregateData(data, aggChoice);
}