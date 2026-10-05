int main() {
    int choice;
    TaskManager taskManager;
    Scheduler scheduler;
    GoalManager goalManager;
    ReminderSystem reminderSystem;
    FeedbackSystem feedbackSystem;
    initTaskManager(&taskManager);
    initScheduler(&scheduler);
    initGoalManager(&goalManager);
    initReminderSystem(&reminderSystem);
    initFeedbackSystem(&feedbackSystem);
    while (1) {
        printf("\n--- TimeMaster Game ---\n");
        printf("1. Create Task\n");
        printf("2. Schedule Task\n");
        printf("3. Set Goal\n");
        printf("4. Show Schedule\n");
        printf("5. Set Reminder\n");
        printf("6. Show Feedback\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createTask(&taskManager);
                break;
            case 2:
                scheduleTask(&scheduler, &taskManager);
                break;
            case 3:
                setGoal(&goalManager);
                break;
            case 4:
                showSchedule(&scheduler);
                break;
            case 5:
                setReminder(&reminderSystem);
                break;
            case 6:
                showFeedback(&feedbackSystem);
                break;
            case 7:
                printf("Exiting game...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}