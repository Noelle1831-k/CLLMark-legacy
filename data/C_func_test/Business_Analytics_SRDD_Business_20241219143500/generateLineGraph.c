void generateLineGraph() {
    printf("Generating line graph...\n");
    int data[] = {5, 10, 15, 20}; 
    int n = sizeof(data) / sizeof(data[0]);
    printf("Line Graph:\n");
    for (int i = 0; i < n; i++) {
        printf("Data %d: ", i + 1);
        for (int j = 0; j < data[i]; j++) {
            printf("-");
        }
        printf(" %d\n", data[i]);
    }
}