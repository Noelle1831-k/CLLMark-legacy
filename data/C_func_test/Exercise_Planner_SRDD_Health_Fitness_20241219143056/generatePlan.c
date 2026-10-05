ExercisePlan generatePlan(User user) {
    ExercisePlan plan;
    switch (user.goal) {
        case 1:
            strcpy(plan.type, "Weight Loss");
            strcpy(plan.exercises, "Cardio, HIIT, Yoga");
            break;
        case 2:
            strcpy(plan.type, "Muscle Gain");
            strcpy(plan.exercises, "Weightlifting, Resistance Training, Pilates");
            break;
        case 3:
            strcpy(plan.type, "Fitness Improvement");
            strcpy(plan.exercises, "Mixed Cardio, Strength Training, Flexibility Exercises");
            break;
        default:
            strcpy(plan.type, "General Fitness");
            strcpy(plan.exercises, "General Cardio, Basic Strength, Stretching");
            break;
    }
    return plan;
}