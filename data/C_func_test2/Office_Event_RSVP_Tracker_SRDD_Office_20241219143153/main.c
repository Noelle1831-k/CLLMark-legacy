int main() {
    printf("Welcome to the Office Event RSVP Tracker!\n");
    initializeEventSystem();
    initializeRSVPSystem();
    initializeCalendarSystem();
    initializeGuestListSystem();
    initializeReportSystem();
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Event\n");
        printf("2. Manage RSVPs\n");
        printf("3. View Calendar\n");
        printf("4. Manage Guest List\n");
        printf("5. Generate Report\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createEvent();
                break;
            case 2:
                manageRSVPs();
                break;
            case 3:
                viewCalendar();
                break;
            case 4:
                manageGuestList();
                break;
            case 5:
                generateReport();
                break;
            case 6:
                printf("Exiting the application.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}