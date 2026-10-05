void addGoal() {
    if (goalCount >= 100) {
        printf("Goal limit reached. Cannot add more goals.\n");
        return;
    }
    Goal newGoal;
    printf("Enter goal name: ");
    scanf(" %[^\n]", newGoal.name);
    printf("Enter target amount: ");
    newGoal.targetAmount = getValidatedFloatInput();
    printf("Enter current amount: ");
    newGoal.currentAmount = getValidatedFloatInput();
    printf("Enter deadline (YYYY-MM-DD): ");
    scanf(" %[^\n]", newGoal.deadline);
    goals[goalCount++] = newGoal;
    printf("Goal added successfully!\n");
}