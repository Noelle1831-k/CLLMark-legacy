void trackSavings(SavingsTracker *tracker) {
    printf("Enter savings amount: ");
    double savings;
    if (scanf("%lf", &savings) != 1 || savings < 0) {
        printf("Invalid input. Please enter a positive number.\n");
        while (getchar() != '\n'); 
        return;
    }
    tracker->currentSavings += savings;
    printf("Current savings: %.2lf/%.2lf\n", tracker->currentSavings, tracker->savingsGoal);
}