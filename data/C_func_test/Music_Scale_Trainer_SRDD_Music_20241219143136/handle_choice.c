void handle_choice(int choice) {
    switch (choice) {
        case 1:
            practice_scales();
            break;
        case 2:
            display_progress();
            break;
        case 3:
            view_resources();
            break;
        case 4:
            printf("Exiting application. Goodbye!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}