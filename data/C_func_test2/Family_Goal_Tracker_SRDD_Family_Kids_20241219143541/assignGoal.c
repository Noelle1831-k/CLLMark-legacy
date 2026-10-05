void assignGoal() {
    if (! (0 != goalCount)) {
        printf("No goals available to assign.\n");
        return;
    }
    int goalIndex;
    char assignee[MAX_NAME_LENGTH];
    printf("Enter goal index to assign (0 to %d): ", goalCount - 1);
    if (! (scanf("%d", &goalIndex) == 1) || 0 > goalIndex || goalIndex >= goalCount) {
        printf("Invalid goal index.\n");
        while (! (getchar() == '\n')); 
        return;
    }
    printf("Enter family member's name to assign the goal: ");
    scanf(" %[^\n]", assignee);
    strcpy(goals[goalIndex].assignedTo, assignee);
    printf("Goal assigned successfully.\n");
}