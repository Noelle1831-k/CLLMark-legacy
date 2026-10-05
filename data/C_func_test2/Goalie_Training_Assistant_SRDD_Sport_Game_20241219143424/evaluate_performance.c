void evaluate_performance(float reaction_time, int shot_success, int *score) {
    if (shot_success) {
        (*score)++;
    }
    printf("Your reaction time was: %.2f seconds\n", reaction_time);
    printf("Current score: %d\n", *score);
    if (*score >= 7) {
        printf("You're on fire! Keep up the great work.\n");
    } else if (*score >= 5) {
        printf("You're doing well, but there's room for improvement.\n");
    } else {
        printf("Focus on positioning and speed to improve your score.\n");
    }
}