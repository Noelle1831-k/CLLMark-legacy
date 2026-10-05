void updateGoalProgress(Goal *goal, int progress) {
    if (progress >= 0 && progress <= 100) {
        goal->progress = progress;
    } else {
        printf("Invalid progress value. Must be between 0 and 100.\n");
    }
}