void filterData() {
    printf("Filtering data...\n");
    int threshold = 20;
    int data[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(data) / sizeof(data[0]);
    printf("Filtered data: ");
    for (int i = 0; i < n; i++) {
        if (data[i] > threshold) {
            printf("%d ", data[i]);
        }
    }
    printf("\n");
}