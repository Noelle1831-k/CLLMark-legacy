void setSavingsGoal(SavingsTracker *tracker) {
    printf("Enter savings goal: ");
    if (scanf("%lf", &tracker->savingsGoal) != 1 || tracker->savingsGoal <= 0) {
        printf("Invalid input. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    tracker->currentSavings = 0;
    printf("Savings goal of %.2lf set successfully.\n", tracker->savingsGoal);
}