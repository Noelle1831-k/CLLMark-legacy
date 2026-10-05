void add_milestone() {
    if (milestone_count >= 100) {
        printf("Milestone limit reached. Cannot add more milestones.\n");
        return;
    }
    Milestone new_milestone;
    printf("Enter goal name: ");
    scanf("%s", new_milestone.goal_name);
    printf("Enter milestone name: ");
    scanf("%s", new_milestone.milestone_name);
    printf("Enter milestone amount: ");
    scanf("%f", &new_milestone.milestone_amount);
    new_milestone.achieved = 0;
    milestones[milestone_count++] = new_milestone;
    printf("Milestone added successfully!\n");
}