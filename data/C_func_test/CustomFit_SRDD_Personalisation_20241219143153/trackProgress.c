void trackProgress(User *user, WorkoutPlan *plan) {
    printf("Tracking progress for user with fitness level %d\n", user->fitnessLevel);
    for (int i = 0; i < plan->numExercises; i++) {
        printf("Tracking progress for exercise: %s\n", plan->exercises[i]);
        printf("Progress: %d%% complete\n", (i + 1) * 20);
    }
}