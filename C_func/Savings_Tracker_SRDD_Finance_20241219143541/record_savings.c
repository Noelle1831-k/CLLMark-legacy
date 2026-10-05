void record_savings(SavingsTracker *tracker, float savings) {
    tracker->current_savings += savings;
    tracker->total_savings_days++;
    printf("You have successfully saved %.2f. Current savings: %.2f.\n", savings, tracker->current_savings);
}