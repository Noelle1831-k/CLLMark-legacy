void displayGoal(const Goal *goal) {
    printf("Goal: %s\n", goal->description);
    printf("Target: %d\n", goal->target);
    printf("Progress: %d%%\n", goal->progress);
}