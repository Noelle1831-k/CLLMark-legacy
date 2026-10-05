void displayVisualization() {
    printf("Displaying Budget Breakdown\n");
    printf("1. View Pie Chart\n");
    printf("2. View Bar Graph\n");
    printf("3. Back to Main Menu\n");
    int choice = getValidatedInput(1, 3);
    switch (choice) {
        case 1:
            viewPieChart();
            break;
        case 2:
            viewBarGraph();
            break;
        case 3:
            return;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}