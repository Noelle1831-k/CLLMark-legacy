void updateGoal() {
    if (goalCount == 0) {
        printf("No goals to update.\n");
        return;
    }
    checkGoals();
    printf("Enter the goal number to update: ");
    int index = getValidatedInput(1, goalCount) - 1;
    printf("Enter new target amount: ");
    scanf("%lf", &goals[index].targetAmount);
    printf("Enter new current amount: ");
    scanf("%lf", &goals[index].currentAmount);
    printf("Goal updated successfully.\n");
}