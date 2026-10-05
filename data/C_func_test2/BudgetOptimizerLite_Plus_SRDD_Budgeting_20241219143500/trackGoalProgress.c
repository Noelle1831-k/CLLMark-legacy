void trackGoalProgress(GoalManager *manager) {
    printf("Enter progress amount: ");
    double progress;
    if (scanf("%lf", &progress) != 1 || progress < 0) {
        printf("Invalid input. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    manager->currentProgress += progress;
    printf("Current goal progress: %.2lf/%.2lf\n", manager->currentProgress, manager->goalAmount);
}