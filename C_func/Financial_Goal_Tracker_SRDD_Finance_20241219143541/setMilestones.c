void setMilestones(Goal goals[], int goalCount) {
    int goalIndex;
    printf("Enter goal index to set milestones: ");
    scanf("%d", &goalIndex);
    clearBuffer(); 
    if (goalIndex < 1 || goalIndex > goalCount) {
        printf("Invalid goal index.\n");
        return;
    }
    Goal *goal = &goals[goalIndex - 1];
    printf("Enter the number of milestones (max %d): ", MAX_MILESTONES);
    scanf("%d", &goal->milestoneCount);
    clearBuffer(); 
    if (goal->milestoneCount > MAX_MILESTONES) {
        printf("Exceeded maximum milestones. Setting to %d.\n", MAX_MILESTONES);
        goal->milestoneCount = MAX_MILESTONES;
    }
    for (int i = 0; i < goal->milestoneCount; i++) {
        printf("Enter milestone %d amount: ", i + 1);
        scanf("%lf", &goal->milestones[i]);
        clearBuffer(); 
    }
    printf("Milestones set successfully.\n");
}