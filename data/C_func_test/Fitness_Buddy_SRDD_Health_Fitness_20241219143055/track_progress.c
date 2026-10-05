void track_progress(User user, WorkoutPlan plan) {
    printf("Tracking progress for %s\n", user.name);
    for (int i = 0; i < plan.exercise_count; i++) {
        printf("Completed: %s\n", plan.exercises[i].name);
    }
}