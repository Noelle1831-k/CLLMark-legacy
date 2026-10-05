Visualization* createVisualization(DataSet *data) {
    Visualization *viz = (Visualization *)malloc(sizeof(Visualization));
    viz->type = CHART_TYPE_BAR;
    printf("Select visualization type (1-Bar, 2-Line, 3-Scatter, 4-Pie): ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            viz->type = CHART_TYPE_BAR;
            generateBarChart(data, viz);
            break;
        case 2:
            viz->type = CHART_TYPE_LINE;
            generateLineGraph(data, viz);
            break;
        case 3:
            viz->type = CHART_TYPE_SCATTER;
            generateScatterPlot(data, viz);
            break;
        case 4:
            viz->type = CHART_TYPE_PIE;
            generatePieChart(data, viz);
            break;
        default:
            printf("Invalid choice. Defaulting to Bar Chart.\n");
            generateBarChart(data, viz);
    }
    return viz;
}