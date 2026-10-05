void handleUserInput() {
    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                editProfile();
                break;
            case 3:
                deleteUser();
                break;
            case 4:
                searchUsers();
                break;
            case 5:
                createEvent();
                break;
            case 6:
                editEvent();
                break;
            case 7:
                deleteEvent();
                break;
            case 8:
                searchEvents();
                break;
            case 9:
                rsvpEvent();
                break;
            case 10:
                sendMessage();
                break;
            case 11:
                viewMessages();
                break;
            case 12:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}