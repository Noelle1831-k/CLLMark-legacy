void WorkoutPlan::generatePlan(const User& user, WorkoutLibrary& library) {
    vector<Exercise> exercises = selectExercises(user, library);
    plan = exercises;
}