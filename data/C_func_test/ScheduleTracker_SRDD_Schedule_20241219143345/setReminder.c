void setReminder() {
    char taskName[50];
    int reminderTime;
    printf("Enter task name for reminder: ");
    scanf("%s", taskName);
    printf("Enter reminder time (in minutes before task): ");
    scanf("%d", &reminderTime);
    printf("Reminder set for task %s, %d minutes before start.\n", taskName, reminderTime);
}