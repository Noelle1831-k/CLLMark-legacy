int main() {
    printf("Welcome to SocialEvent!\n");
    initialize_users();
    initialize_events();
    initialize_network();
    int running = 1;
    while (running) {
        printf("\n1. Create User\n2. Browse Events\n3. RSVP to Event\n4. Connect with Users\n5. View Connections\n6. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_user();
                break;
            case 2:
                browse_events();
                break;
            case 3:
                rsvp_event();
                break;
            case 4:
                connect_users();
                break;
            case 5:
                view_connections();
                break;
            case 6:
                running = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    cleanup_users();
    cleanup_events();
    cleanup_network();
    printf("Thank you for using SocialEvent!\n");
    return 0;
}