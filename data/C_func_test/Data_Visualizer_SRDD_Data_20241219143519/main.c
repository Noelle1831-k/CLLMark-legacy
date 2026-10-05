int main() {
    int choice = 0;
    DataSet *data = NULL;
    Visualization *viz = NULL;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (data) {
                    freeDataSet(data);
                    data = NULL;
                }
                data = importData("data.csv");
                if (data != NULL) {
                    printf("Data imported successfully!\n");
                } else {
                    printf("Failed to import data.\n");
                }
                break;
            case 2:
                if (data == NULL) {
                    printf("No data available. Please import data first.\n");
                } else {
                    if (viz) {
                        freeVisualization(viz);
                        viz = NULL;
                    }
                    viz = createVisualization(data);
                    if (viz != NULL) {
                        printf("Visualization created successfully!\n");
                    } else {
                        printf("Failed to create visualization.\n");
                    }
                }
                break;
            case 3:
                if (viz == NULL) {
                    printf("No visualization available. Please create a visualization first.\n");
                } else {
                    exportVisualization(viz, "visualization.png");
                    printf("Visualization exported successfully!\n");
                }
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                if (data) freeDataSet(data);
                if (viz) freeVisualization(viz);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}