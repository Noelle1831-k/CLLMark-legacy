void updateProgress(Goal goals[], int goalCount) {
    int goalIndex;
    double amount;
    printf("Enter goal index to update progress: ");
    scanf("%d", &goalIndex);
    if (goalIndex < 1 || goalIndex > goalCount) {
        printf("Invalid goal index.\n");
        return;
    }
    printf("Enter amount to add to current progress: ");
    scanf("%lf", &amount);
    if (amount < 0) {
        printf("Amount cannot be negative.\n");
        return;
    }
    goals[goalIndex - 1].currentAmount += amount;
    printf("Progress updated successfully.\n");
}