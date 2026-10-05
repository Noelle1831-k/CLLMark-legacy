void displayGoals() {
    if (goalCount == 0) {
        printf("No goals to display.\n");
        return;
    }
    printf("\n--- Your Financial Goals ---\n");
    for (int i = 0; i < goalCount; i++) {
        printf("Goal %d:\n", i + 1);
        printf("Name: %s\n", goals[i].name);
        printf("Target Amount: %.2f\n", goals[i].targetAmount);
        printf("Current Amount: %.2f\n", goals[i].currentAmount);
        printf("Deadline: %s\n", goals[i].deadline);
        printf("---------------------------\n");
    }
}