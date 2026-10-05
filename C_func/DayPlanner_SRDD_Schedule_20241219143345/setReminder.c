void setReminder() {
    char taskName[100];
    int hour, minute;
    printf("Enter task name for reminder: ");
    scanf("%s", taskName);
    printf("Enter reminder time (HH MM): ");
    scanf("%d %d", &hour, &minute);
    printf("Reminder set for task '%s' at %02d:%02d.\n", taskName, hour, minute);
}