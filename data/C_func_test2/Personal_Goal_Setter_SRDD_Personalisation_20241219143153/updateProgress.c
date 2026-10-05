void updateProgress(Goal goals[MAX_GOALS], Progress progress[MAX_GOALS], int goalCount) {
    int goalIndex;
    printf("Enter the goal index to update progress (0 to %d): ", goalCount - 1);
    scanf("%d", &goalIndex);
    if (goalIndex >= 0 && goalIndex < goalCount) {
        int newProgress;
        printf("Enter new progress for goal '%s': ", goals[goalIndex].name);
        scanf("%d", &newProgress);
        progress[goalIndex].currentProgress = newProgress;
        printf("Progress for goal '%s' updated to %d!\n", goals[goalIndex].name, newProgress);
    } else {
        printf("Invalid goal index!\n");
    }
}