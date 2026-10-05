void setGoal() {
    if (goalCount >= MAX_GOALS) {
        printf("Goal limit reached. Cannot add more goals.\n");
        return;
    }
    Goal newGoal;
    printf("Enter goal name: ");
    scanf("%s", newGoal.name);
    printf("Enter target amount: ");
    scanf("%lf", &newGoal.targetAmount);
    newGoal.currentAmount = 0;
    goals[goalCount++] = newGoal;
    printf("Goal set successfully.\n");
}