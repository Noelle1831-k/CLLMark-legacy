int main() {
    printf("Welcome to TimeTracker!\n");
    TaskManager taskManager;
    AppointmentManager appointmentManager;
    DeadlineManager deadlineManager;
    RecommendationEngine recommendationEngine;
    ReminderSystem reminderSystem;
    UserAnalysis userAnalysis;
    initTaskManager(&taskManager);
    initAppointmentManager(&appointmentManager);
    initDeadlineManager(&deadlineManager);
    initRecommendationEngine(&recommendationEngine);
    initReminderSystem(&reminderSystem);
    initUserAnalysis(&userAnalysis);
    int choice;
    while (1) {
        printf("\n1. Add Task\n2. Remove Task\n3. List Tasks\n");
        printf("4. Add Appointment\n5. Remove Appointment\n6. List Appointments\n");
        printf("7. Add Deadline\n8. Remove Deadline\n9. List Deadlines\n");
        printf("10. Generate Recommendations\n11. Set Reminder\n12. Analyze User Data\n13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addTask(&taskManager);
                break;
            case 2:
                removeTask(&taskManager);
                break;
            case 3:
                listTasks(&taskManager);
                break;
            case 4:
                addAppointment(&appointmentManager);
                break;
            case 5:
                removeAppointment(&appointmentManager);
                break;
            case 6:
                listAppointments(&appointmentManager);
                break;
            case 7:
                addDeadline(&deadlineManager);
                break;
            case 8:
                removeDeadline(&deadlineManager);
                break;
            case 9:
                listDeadlines(&deadlineManager);
                break;
            case 10:
                generateRecommendations(&recommendationEngine, &taskManager, &appointmentManager, &deadlineManager);
                break;
            case 11:
                setReminder(&reminderSystem);
                break;
            case 12:
                analyzeUserData(&userAnalysis);
                break;
            case 13:
                printf("Exiting TimeTracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}