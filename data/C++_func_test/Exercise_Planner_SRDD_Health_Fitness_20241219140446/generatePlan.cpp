void ExercisePlan::generatePlan(string goals) {
    plan.clear(); 
    if (goals == "Weight Loss") {
        Exercise e1, e2;
        e1.setExerciseDetails("Running", "Cardio", 30);
        e2.setExerciseDetails("Cycling", "Cardio", 45);
        plan.push_back(e1);
        plan.push_back(e2);
    } else if (goals == "Muscle Gain") {
        Exercise e1, e2;
        e1.setExerciseDetails("Weight Lifting", "Strength", 60);
        e2.setExerciseDetails("Push Ups", "Strength", 30);
        plan.push_back(e1);
        plan.push_back(e2);
    } else {
        Exercise e1, e2;
        e1.setExerciseDetails("Yoga", "Flexibility", 60);
        e2.setExerciseDetails("Pilates", "Flexibility", 45);
        plan.push_back(e1);
        plan.push_back(e2);
    }
}