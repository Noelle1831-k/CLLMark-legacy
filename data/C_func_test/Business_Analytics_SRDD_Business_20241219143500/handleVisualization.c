void handleVisualization() {
    printf("Choose visualization type:\n");
    printf("1. Bar Chart\n");
    printf("2. Pie Chart\n");
    printf("3. Line Graph\n");
    int vizChoice;
    scanf("%d", &vizChoice);
    switch (vizChoice) {
        case 1:
            generateBarChart();
            break;
        case 2:
            generatePieChart();
            break;
        case 3:
            generateLineGraph();
            break;
        default:
            printf("Invalid choice!\n");
    }
}