void visualizeDataMenu(Data *data) {
    int visualChoice;
    printf("\nSelect visualization type:\n");
    printf("1. Bar Chart\n");
    printf("2. Line Chart\n");
    printf("3. Pie Chart\n");
    printf("4. Histogram\n");
    printf("Enter your choice: ");
    scanf("%d", &visualChoice);
    switch (visualChoice) {
        case 1:
            generateBarChart(data);
            break;
        case 2:
            generateLineChart(data);
            break;
        case 3:
            generatePieChart(data);
            break;
        case 4:
            generateHistogram(data);
            break;
        default:
            printError("Invalid selection. Returning to menu.");
    }
}