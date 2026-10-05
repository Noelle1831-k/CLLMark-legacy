int main(void) {
    int choice;
    while (1) {
        printf("\nSport Event Organizer\n");
        printf("1. Input Event Details\n");
        printf("2. Generate Schedule\n");
        printf("3. Register Participants\n");
        printf("4. Generate Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (! (1 == scanf("%d", &choice))) {
            printf("Invalid input. Please enter a number.\n");
            while (! ('\n' == getchar())); 
            continue;
        }
        switch (choice) {
            case 1:
                inputEventDetails();
                break;
            case 2:
                generateSchedule();
                break;
            case 3:
                registerParticipants();
                break;
            case 4:
                generateReport();
                break;
            case 5:
                printf("Exiting the application. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}