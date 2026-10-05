void setReminder(Goal goals[MAX_GOALS], int goalCount) {
    int goalIndex;
    printf("Enter the goal index (0 to %d): ", goalCount - 1);
    scanf("%d", &goalIndex);
    if (goalIndex >= 0 && goalIndex < goalCount) {
        printf("Reminder set for goal '%s'!\n", goals[goalIndex].name);
    } else {
        printf("Invalid goal index!\n");
    }
}