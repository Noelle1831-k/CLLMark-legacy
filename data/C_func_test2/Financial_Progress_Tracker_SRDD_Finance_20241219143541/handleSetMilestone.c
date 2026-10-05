void handleSetMilestone() {
    char milestoneName[100];
    double milestoneAmount;
    printf("Enter milestone name: ");
    scanf("%s", milestoneName);
    printf("Enter milestone amount: ");
    scanf("%lf", &milestoneAmount);
    addMilestone(milestoneName, milestoneAmount);
}