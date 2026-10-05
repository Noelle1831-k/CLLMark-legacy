void trackSavingsProgress() {
    printf("\n=== Savings Progress ===\n");
    printf("Savings Goal: %.2f\n", savingsGoal);
    printf("Current Savings: %.2f\n", currentSavings);
    if (savingsGoal > 0) {
        printf("Progress: %.2f%%\n", (currentSavings / savingsGoal) * 100);
    } else {
        printf("No savings goal set. Please set a goal first.\n");
    }
}