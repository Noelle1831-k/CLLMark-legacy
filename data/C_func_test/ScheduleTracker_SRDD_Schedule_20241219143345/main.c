int main() {
    initializeTaskManager();
    initializeReminders();
    char choice;
    while (1) {
        printf("\nScheduleTracker Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Schedule\n");
        printf("3. Set Reminder\n");
        printf("4. Generate Report\n");
        printf("5. Visual Overview\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                addTask();
                break;
            case '2':
                displaySchedule();
                break;
            case '3':
                setReminder();
                break;
            case '4':
                generateReport();
                break;
            case '5':
                displayVisualOverview();
                break;
            case '6':
                printf("Exiting ScheduleTracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}