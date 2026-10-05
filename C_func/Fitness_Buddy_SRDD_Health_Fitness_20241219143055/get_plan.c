void get_plan(WorkoutPlan plan) {
    printf("Workout Plan for %s:\n", plan.user_name);
    for (int i = 0; i < plan.exercise_count; i++) {
        printf("Exercise: %s | Sets: %d | Reps: %d\n", plan.exercises[i].name, plan.exercises[i].sets, plan.exercises[i].reps);
    }
}