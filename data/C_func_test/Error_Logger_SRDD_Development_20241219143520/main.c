int main() {
    ErrorLogger logger;
    initialize_logger(&logger);
    int choice;
    char input[MAX_INPUT_SIZE];
    while (1) {
        display_menu();
        fgets(input, MAX_INPUT_SIZE, stdin);
        choice = atoi(input);
        switch (choice) {
            case 1:
                add_error_ui(&logger);
                break;
            case 2:
                search_error_ui(&logger);
                break;
            case 3:
                filter_errors_ui(&logger);
                break;
            case 4:
                display_all_errors(&logger);
                break;
            case 5:
                export_errors_to_file(&logger);
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}