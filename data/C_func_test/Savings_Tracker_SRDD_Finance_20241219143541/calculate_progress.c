void calculate_progress(SavingsTracker *tracker) {
    float progress = (tracker->current_savings / tracker->savings_goal) * 100;
    printf("Current savings: %.2f\n", tracker->current_savings);
    printf("Savings goal: %.2f\n", tracker->savings_goal);
    printf("You have reached %.2f%% of your savings goal.\n", progress);
}