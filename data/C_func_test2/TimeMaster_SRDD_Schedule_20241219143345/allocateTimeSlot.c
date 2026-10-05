void allocateTimeSlot() {
    int hour;
    char taskName[50];
    printf("Enter hour (0-23): ");
    scanf("%d", &hour);
    if (hour < 0 || hour >= MAX_SLOTS) {
        printf("Invalid hour. Please try again.\n");
        return;
    }
    printf("Enter task name: ");
    scanf(" %[^\n]", taskName);
    strcpy(schedule[hour].taskName, taskName);
    printf("Time slot allocated successfully!\n");
}