void generateBarChart() {
    printf("Generating bar chart...\n");
    int data[] = {5, 10, 15, 20};
    int n = sizeof(data) / sizeof(data[0]);
    displayGraph("Bar Chart", data, n);
}