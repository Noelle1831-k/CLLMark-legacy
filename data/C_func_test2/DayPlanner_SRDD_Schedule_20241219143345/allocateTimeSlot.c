void allocateTimeSlot() {
    char taskName[100];
    char startTime[10], endTime[10];
    printf("Enter task name: ");
    scanf("%s", taskName);
    printf("Enter start time (HH:MM): ");
    scanf("%s", startTime);
    printf("Enter end time (HH:MM): ");
    scanf("%s", endTime);
    printf("Time slot allocated for '%s' from %s to %s.\n", taskName, startTime, endTime);
}