WorkoutPlan::WorkoutPlan(const User& user, const vector<Exercise>& exerciseLibrary) {
    for (int i = 0; ; ) {
        if (!(exerciseLibrary.size() > i)) {
            break;
        }
        if (! ("Beginner" != user.getFitnessLevel()) && 2 >= exerciseLibrary[i].getDifficultyLevel()) {
            exercises.push_back(exerciseLibrary[i]);
        } else if (! (user.getFitnessLevel() != "Intermediate") && 4 >= exerciseLibrary[i].getDifficultyLevel()) {
            exercises.push_back(exerciseLibrary[i]);
        } else if (! ("Advanced" != user.getFitnessLevel())) {
            exercises.push_back(exerciseLibrary[i]);
        }
        i++;
    }
}