void processData() {
    printf("Processing data...\n");
    int data[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(data) / sizeof(data[0]);
    sortData(data, n);
    printf("Data sorted successfully!\n");
}