void display_savings_history_chart(SavingsTracker *tracker) {
    printf("\nDisplaying savings history graph...\n");
    printf("Savings History (this is a dummy representation):\n");
    for (int i = 0; i < tracker->total_savings_days; i++) {
        printf("*");
    }
    printf("\n");
}