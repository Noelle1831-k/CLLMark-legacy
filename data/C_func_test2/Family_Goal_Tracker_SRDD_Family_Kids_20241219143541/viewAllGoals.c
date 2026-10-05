void viewAllGoals() {
    if (goalCount == 0) {
        printf("No goals available.\n");
        return;
    }
    printf("\n=== All Goals ===\n");
    for (int i = 0; i < goalCount; i++) {
        printf("Goal %d: %s\n", i, goals[i].name);
        printf("Assigned to: %s\n", goals[i].assignedTo);
        printf("Progress: %d%%\n", goals[i].progress);
        printf("Deadline: %d days from today\n", goals[i].deadline);
        printf("----------------------------\n");
    }
}