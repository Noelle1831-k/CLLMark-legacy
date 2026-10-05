void setReminder() {
    if (goalCount == 0) {
        printf("No goals to set reminders for.\n");
        return;
    }
    int goalIndex;
    printf("Enter the goal number to set a reminder: ");
    goalIndex = getValidatedIntegerInput() - 1;
    if (goalIndex < 0 || goalIndex >= goalCount) {
        printf("Invalid goal number.\n");
        return;
    }
    printf("Reminder set for goal: %s (Deadline: %s)\n", goals[goalIndex].name, goals[goalIndex].deadline);
}