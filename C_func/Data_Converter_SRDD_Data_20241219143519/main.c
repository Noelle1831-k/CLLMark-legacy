int main() {
    int choice;
    char input_file[256], output_file[256], format[10];
    DataSet *data = NULL;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the input file path: ");
                scanf("%s", input_file);
                printf("Enter the file format (csv, json, xml, xls): ");
                scanf("%s", format);
                data = import_data(input_file, format);
                if (data) {
                    printf("Data imported successfully.\n");
                } else {
                    printf("Failed to import data.\n");
                }
                break;
            case 2:
                if (data) {
                    printf("Processing data...\n");
                    process_data(data);
                    printf("Data processed successfully.\n");
                } else {
                    printf("No data to process. Please import data first.\n");
                }
                break;
            case 3:
                if (data) {
                    printf("Enter the output file path: ");
                    scanf("%s", output_file);
                    printf("Enter the desired output format (csv, json, xml, xls): ");
                    scanf("%s", format);
                    if (convert_data(data, output_file, format)) {
                        printf("Data converted and saved successfully.\n");
                    } else {
                        printf("Failed to convert data.\n");
                    }
                } else {
                    printf("No data to convert. Please import data first.\n");
                }
                break;
            case 4:
                printf("Exiting the application. Goodbye!\n");
                if (data) {
                    free_data(data);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}