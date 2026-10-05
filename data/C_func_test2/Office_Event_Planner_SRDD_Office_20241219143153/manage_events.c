void manage_events() {
    int choice;
    while (1) {
        printf("\n--- Manage Events ---\n");
        printf("1. Create Event\n");
        printf("2. Delete Event\n");
        printf("3. List Events\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_event();
                break;
            case 2:
                delete_event();
                break;
            case 3:
                list_events();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}