void viewGoals(const Goal goals[], int goalCount) {
    if (goalCount == 0) {
        printf("No goals to display.\n");
        return;
    }
    for (int i = 0; i < goalCount; i++) {
        printf("\nGoal %d: %s\n", i + 1, goals[i].name);
        printf("Target Amount: %.2f\n", goals[i].targetAmount);
        printf("Current Amount: %.2f\n", goals[i].currentAmount);
        printf("Milestones: ");
        for (int j = 0; j < goals[i].milestoneCount; j++) {
            printf("%.2f ", goals[i].milestones[j]);
        }
        printf("\n");
    }
}