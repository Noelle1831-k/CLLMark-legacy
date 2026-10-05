void handle_user_input(MeetingManager *manager) {
    int choice;
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_meeting(manager);
                break;
            case 2:
                view_meeting(manager);
                break;
            case 3:
                edit_meeting(manager);
                break;
            case 4:
                delete_meeting(manager);
                break;
            case 5:
                list_all_meetings(manager);
                break;
            case 6:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}