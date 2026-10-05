int main() {
    char filename[256] = "";
    char fields[256] = "";
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();
        switch (choice) {
            case 1:
                printf("Enter the file path: ");
                fgets(filename, 256, stdin);
                filename[strcspn(filename, "\n")] = '\0'; 
                handle_file_import(filename);
                break;
            case 2:
                if (strlen(filename) == 0) {
                    printf("No file has been imported. Please import a dataset first.\n");
                } else {
                    printf("Enter the fields to analyze (comma-separated): ");
                    fgets(fields, 256, stdin);
                    fields[strcspn(fields, "\n")] = '\0'; 
                    process_analysis(filename, fields);
                }
                break;
            case 3:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}