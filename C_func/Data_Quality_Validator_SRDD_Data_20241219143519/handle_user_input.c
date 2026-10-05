void handle_user_input(int choice, const char *filename) {
    switch (choice) {
        case 1:
            validate_missing_values(filename);
            break;
        case 2:
            validate_duplicates(filename);
            break;
        case 3:
            validate_data_types(filename);
            break;
        case 4:
            printf("Exiting the application. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}