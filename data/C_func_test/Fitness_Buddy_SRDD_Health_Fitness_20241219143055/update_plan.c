void update_plan(WorkoutPlan *plan, Exercise exercise) {
    plan->exercises[plan->exercise_count++] = exercise;
}