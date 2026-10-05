void set_goal(SavingsGoal *goal, float target) {
    goal->target = target;
    goal->current = 0;
    printf("Savings goal set to %.2f\n", target);
}