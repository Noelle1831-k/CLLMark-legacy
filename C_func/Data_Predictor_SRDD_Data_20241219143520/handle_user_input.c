void handle_user_input(int choice) {
    switch (choice) {
        case 1:
            import_data();
            break;
        case 2:
            train_model();
            break;
        case 3:
            predict();
            break;
        case 4:
            printf("Exiting the application. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}