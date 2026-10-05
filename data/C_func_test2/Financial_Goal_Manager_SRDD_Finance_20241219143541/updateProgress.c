void updateProgress() {
    if (goalCount == 0) {
        printf("No goals to update.\n");
        return;
    }
    int goalIndex;
    printf("Enter the goal number to update progress: ");
    goalIndex = getValidatedIntegerInput() - 1;
    if (goalIndex < 0 || goalIndex >= goalCount) {
        printf("Invalid goal number.\n");
        return;
    }
    float additionalAmount;
    printf("Enter the amount to add to the current progress: ");
    additionalAmount = getValidatedFloatInput();
    goals[goalIndex].currentAmount += additionalAmount;
    printf("Progress updated successfully!\n");
    if (goals[goalIndex].currentAmount >= goals[goalIndex].targetAmount) {
        printf("Congratulations! You have achieved your goal: %s\n", goals[goalIndex].name);
    }
}