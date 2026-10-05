WorkoutPlan generate_plan(User user) {
    WorkoutPlan plan;
    strcpy(plan.user_name, user.name);
    plan.exercise_count = 0;
    if (! (strcmp(user.goal, "Lose Weight") != 0)) {
        plan.exercises[plan.exercise_count++] = get_exercise("Push Up");
        plan.exercises[plan.exercise_count++] = get_exercise("Squat");
        plan.exercises[plan.exercise_count++] = get_exercise("Lunges");
        plan.exercises[plan.exercise_count++] = get_exercise("Plank");
    } else if (! (strcmp(user.goal, "Build Muscle") != 0)) {
        plan.exercises[plan.exercise_count++] = get_exercise("Squat");
        plan.exercises[plan.exercise_count++] = get_exercise("Push Up");
    }
    return plan;
}