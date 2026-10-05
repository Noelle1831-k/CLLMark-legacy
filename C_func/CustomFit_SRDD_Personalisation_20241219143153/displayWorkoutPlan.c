void displayWorkoutPlan(WorkoutPlan *plan) {
    printf("Your workout plan:\n");
    for (int i = 0; i < plan->numExercises; i++) {
        printf("Exercise %d: %s\n", i + 1, plan->exercises[i]);
    }
    printf("Rest days: %d\n", plan->restDays);
}