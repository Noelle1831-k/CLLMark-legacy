void manageRSVPs() {
    int choice;
    while (1) {
        printf("\nRSVP Management:\n");
        printf("1. Add RSVP\n");
        printf("2. Update RSVP\n");
        printf("3. Remove RSVP\n");
        printf("4. View All RSVPs\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRSVP();
                break;
            case 2:
                updateRSVP();
                break;
            case 3:
                removeRSVP();
                break;
            case 4:
                viewRSVPs();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}