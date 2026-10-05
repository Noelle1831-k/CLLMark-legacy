int main() {
    int choice;
    char filename[100];
    double *data = NULL;
    int data_size = 0;
    while (1) {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }
        switch (choice) {
            case 1:
                printf("Enter the filename to load data: ");
                scanf("%s", filename);
                free_memory(data); 
                data = load_data(filename, &data_size);
                if (data) {
                    printf("Data loaded successfully. Size: %d\n", data_size);
                } else {
                    printf("Failed to load data.\n");
                }
                break;
            case 2:
                if (data) {
                    visualize_data(data, data_size);
                } else {
                    printf("No data loaded. Please load data first.\n");
                }
                break;
            case 3:
                if (data) {
                    perform_predictive_modeling(data, data_size);
                } else {
                    printf("No data loaded. Please load data first.\n");
                }
                break;
            case 4:
                if (data) {
                    perform_hypothesis_testing(data, data_size);
                } else {
                    printf("No data loaded. Please load data first.\n");
                }
                break;
            case 5:
                if (data) {
                    analyze_trends(data, data_size);
                } else {
                    printf("No data loaded. Please load data first.\n");
                }
                break;
            case 6:
                if (data) {
                    double mean = calculate_mean(data, data_size);
                    printf("Data Summary:\n");
                    printf("Mean: %.2f\n", mean);
                } else {
                    printf("No data loaded. Please load data first.\n");
                }
                break;
            case 7:
                printf("Exiting Data Analyzer Plus. Goodbye!\n");
                free_memory(data);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    free_memory(data);
    return 0;
}