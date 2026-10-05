void manageReminders() {
    int choice;
    do {
        printf("\nReminder Management:\n1. Schedule Reminder\n2. Update Reminder\n3. Trigger Reminders\n4. Back\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scheduleReminder();
                break;
            case 2:
                updateReminder();
                break;
            case 3:
                triggerReminders();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}