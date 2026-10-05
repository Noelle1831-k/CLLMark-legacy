void set_goal(SavingsTracker *tracker, float target, int days) {
    tracker->savings_goal = target;
    tracker->days_for_goal = days;
    tracker->daily_savings_target = tracker->savings_goal / tracker->days_for_goal;
    printf("Savings goal set to %.2f with a target of %.2f per day over %d days.\n", tracker->savings_goal, tracker->daily_savings_target, tracker->days_for_goal);
}