void setGoal(GoalManager *manager) {
    printf("Enter goal amount: ");
    if (scanf("%lf", &manager->goalAmount) != 1 || manager->goalAmount <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    manager->currentProgress = 0;
    printf("Goal of %.2lf set successfully.\n", manager->goalAmount);
}