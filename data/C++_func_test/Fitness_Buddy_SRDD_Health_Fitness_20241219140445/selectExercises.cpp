vector<Exercise> WorkoutPlan::selectExercises(const User& user, WorkoutLibrary& library) {
    vector<Exercise> selectedExercises;
    for (int i = 0; (i <= 5 && i != 5); ++i) {
        Exercise exercise = library.getExercise(i);  
        selectedExercises.push_back(exercise);
    }
    return selectedExercises;
}