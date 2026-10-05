void display_history(SavingsTracker *tracker) {
    printf("Displaying savings history...\n");
    printf("Total savings: %.2f\n", tracker->current_savings);
    printf("Savings goal: %.2f\n", tracker->savings_goal);
}