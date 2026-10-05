void handle_user_choice(int choice) {
    static double dataset[MAX_DATASET_SIZE][MAX_VARIABLES];
    static int rows = 0, cols = 0;
    switch (choice) {
        case 1:
            printf("Importing dataset...\n");
            if (import_dataset("dataset.csv", dataset, &rows, &cols)) {
                printf("Dataset imported successfully! Rows: %d, Columns: %d\n", rows, cols);
            } else {
                printf("Failed to import dataset. Please check the file and try again.\n");
            }
            break;
        case 2:
            printf("Calculating correlation...\n");
            if (rows > 0 && cols > 0) {
                calculate_correlation(dataset, rows, cols);
            } else {
                printf("No dataset available. Please import a dataset first.\n");
            }
            break;
        case 3:
            printf("Generating visualization...\n");
            if (rows > 0 && cols > 0) {
                generate_visualization(dataset, rows, cols);
            } else {
                printf("No dataset available. Please import a dataset first.\n");
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}