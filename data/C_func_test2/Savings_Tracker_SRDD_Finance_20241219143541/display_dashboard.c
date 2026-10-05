void display_dashboard(SavingsTracker *tracker) {
    printf("\n==== Savings Tracker Dashboard ====\n");
    printf("Current Savings: %.2f\n", tracker->current_savings);
    printf("Savings Goal: %.2f\n", tracker->savings_goal);
    printf("Daily Savings Target: %.2f\n", tracker->daily_savings_target);
}