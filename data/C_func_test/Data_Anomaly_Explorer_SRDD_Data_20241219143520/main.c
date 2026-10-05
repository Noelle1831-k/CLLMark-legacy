int main() {
    char filename[100];
    double **data = NULL;
    int rows, cols, choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the filename: ");
                scanf("%s", filename);
                data = loadCSV(filename, &rows, &cols);
                if (data == NULL) {
                    printf("Error loading file.\n");
                } else {
                    printf("Dataset loaded successfully.\n");
                }
                break;
            case 2:
                if (data == NULL) {
                    printf("Please import a dataset first.\n");
                } else {
                    printf("Detecting anomalies...\n");
                    zScoreAnomalyDetection(data, rows, cols, 2.0);
                }
                break;
            case 3:
                if (data == NULL) {
                    printf("Please import a dataset first.\n");
                } else {
                    scatterPlot(data, rows, cols, 0, 1);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                if (data != NULL) free2DArray(data, rows);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}