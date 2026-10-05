void ExercisePlan::removeExercise(Exercise e) {
    for (int i = 0; i < plan.size(); i++) {
        if (plan[i].getExerciseDetails() == e.getExerciseDetails()) {
            plan.erase(plan.begin() + i);
            break;
        }
    }
}