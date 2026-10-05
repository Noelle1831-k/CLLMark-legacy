int main() {
    char file_path[256];
    Dataset *dataset = NULL;
    int choice, fill_choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter file path to import dataset: ");
                scanf("%s", file_path);
                dataset = import_dataset(file_path);
                if (dataset) {
                    printf("Dataset imported successfully.\n");
                } else {
                    printf("Failed to import dataset.\n");
                }
                break;
            case 2:
                if (dataset) {
                    remove_duplicates(dataset);
                    printf("Duplicates removed successfully.\n");
                } else {
                    printf("No dataset loaded.\n");
                }
                break;
            case 3:
                if (dataset) {
                    display_missing_values_options();
                    printf("Enter your choice: ");
                    scanf("%d", &fill_choice);
                    switch (fill_choice) {
                        case 1:
                            fill_missing_values_mean(dataset);
                            printf("Missing values filled with mean.\n");
                            break;
                        case 2:
                            fill_missing_values_median(dataset);
                            printf("Missing values filled with median.\n");
                            break;
                        case 3:
                            fill_missing_values_mode(dataset);
                            printf("Missing values filled with mode.\n");
                            break;
                        case 4:
                            fill_missing_values_zero(dataset);
                            printf("Missing values filled with zero.\n");
                            break;
                        case 5:
                            printf("Canceled missing value filling.\n");
                            break;
                        default:
                            printf("Invalid option.\n");
                    }
                } else {
                    printf("No dataset loaded.\n");
                }
                break;
            case 4:
                if (dataset) {
                    standardize_data_formats(dataset);
                    printf("Data formats standardized successfully.\n");
                } else {
                    printf("No dataset loaded.\n");
                }
                break;
            case 5:
                if (dataset) {
                    normalize_data(dataset);
                    printf("Data normalized successfully.\n");
                } else {
                    printf("No dataset loaded.\n");
                }
                break;
            case 6:
                if (dataset) {
                    printf("Enter file path to export cleaned dataset: ");
                    scanf("%s", file_path);
                    export_dataset(dataset, file_path);
                    printf("Dataset exported successfully.\n");
                } else {
                    printf("No dataset loaded.\n");
                }
                break;
            case 7:
                printf("Exiting Data Cleanser. Goodbye!\n");
                if (dataset) {
                    free_dataset(dataset);
                }
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}