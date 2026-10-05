void update_goal(SavingsGoal *goal, float amount) {
    goal->current += amount;
    printf("Updated savings: %.2f\n", goal->current);
}