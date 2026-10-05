void handle_user_input() {
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            manage_connections();
            break;
        case 2:
            manage_profiles();
            break;
        case 3:
            manage_feed();
            break;
        case 4:
            exit_application();
            break;
        default:
            printf("Invalid choice! Please try again.\n");
    }
}