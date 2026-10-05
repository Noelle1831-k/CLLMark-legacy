void aggregateData() {
    printf("Aggregating data...\n");
    int data[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(data) / sizeof(data[0]);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    printf("Sum of data: %d\n", sum);
}