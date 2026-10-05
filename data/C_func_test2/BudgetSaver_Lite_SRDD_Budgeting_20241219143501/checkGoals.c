void checkGoals() {
    if (goalCount == 0) {
        printf("No goals available.\n");
        return;
    }
    printf("Listing all goals:\n");
    for (int i = 0; i < goalCount; i++) {
        printf("%d. %s - Target: $%.2f, Current: $%.2f\n", i + 1, goals[i].name, goals[i].targetAmount, goals[i].currentAmount);
    }
}