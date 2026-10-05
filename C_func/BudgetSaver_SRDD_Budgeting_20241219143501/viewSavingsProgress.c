void viewSavingsProgress() {
    printf("\n=== Savings Progress ===\n");
    printf("Savings Goal: $%.2f\n", savingsGoal);
    printf("Total Savings: $%.2f\n", totalSavings);
    if (savingsGoal > 0) {
        printf("Progress: %.2f%%\n", (totalSavings / savingsGoal) * 100);
    } else {
        printf("No savings goal set.\n");
    }
}