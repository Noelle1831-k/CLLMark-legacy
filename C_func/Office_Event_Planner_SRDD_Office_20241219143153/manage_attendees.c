void manage_attendees() {
    int choice;
    while (1) {
        printf("\n--- Manage Attendees ---\n");
        printf("1. Add Attendee\n");
        printf("2. Remove Attendee\n");
        printf("3. List Attendees\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_attendee();
                break;
            case 2:
                remove_attendee();
                break;
            case 3:
                list_attendees();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}