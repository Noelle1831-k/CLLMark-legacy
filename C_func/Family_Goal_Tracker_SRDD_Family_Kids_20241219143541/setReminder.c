void setReminder() {
    if (goalCount == 0) {
        printf("No goals available to set reminders.\n");
        return;
    }
    int goalIndex;
    printf("Enter goal index to set a reminder for (0 to %d): ", goalCount - 1);
    if (scanf("%d", &goalIndex) != 1 || goalIndex < 0 || goalIndex >= goalCount) {
        printf("Invalid goal index.\n");
        while (getchar() != '\n'); 
        return;
    }
    printf("Reminder set for goal: %s\n", goals[goalIndex].name);
}