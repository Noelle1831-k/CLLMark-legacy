int main(void) {
    DataImporter dataImporter;
    Visualizer visualizer;
    Customizer customizer;
    Exporter exporter;
    int choice;
    printf("Welcome to the Data Visualizer!\n");
    printf("Importing data...\n");
    dataImporter.importData();
    while (true) {
        printf("\nChoose a visualization type:\n");
        printf("1. Bar Chart\n");
        printf("2. Line Graph\n");
        printf("3. Scatter Plot\n");
        printf("4. Pie Chart\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        cin >> choice;
        if (cin.fail()) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            clearInputBuffer();
            continue;
        }
        switch (choice) {
            case 1:
                visualizer.createBarChart();
                break;
            case 2:
                visualizer.createLineGraph();
                break;
            case 3:
                visualizer.createScatterPlot();
                break;
            case 4:
                visualizer.createPieChart();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }
        printf("Customizing visualization...\n");
        customizer.customizeAppearance();
        printf("Choose export format:\n");
        printf("1. Export as Image\n");
        printf("2. Export as Link\n");
        printf("Enter your choice: ");
        cin >> choice;
        if (cin.fail()) {
            printf("Invalid input. Exporting as image by default.\n");
            clearInputBuffer();
            exporter.exportAsImage();
            continue;
        }
        switch (choice) {
            case 1:
                exporter.exportAsImage();
                break;
            case 2:
                exporter.exportAsLink();
                break;
            default:
                printf("Invalid choice. Exporting as image by default.\n");
                exporter.exportAsImage();
        }
        printf("Visualization complete!\n");
    }
    return 0;
}