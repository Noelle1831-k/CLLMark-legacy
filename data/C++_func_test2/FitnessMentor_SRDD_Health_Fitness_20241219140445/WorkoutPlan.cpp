WorkoutPlan::WorkoutPlan(const User& user, const vector<Exercise>& exerciseLibrary) {
    for (int i = 0; i < exerciseLibrary.size(); ++i) {
        if (user.getFitnessLevel() == "Beginner" && exerciseLibrary[i].getDifficultyLevel() <= 2) {
            exercises.push_back(exerciseLibrary[i]);
        } else if (user.getFitnessLevel() == "Intermediate" && exerciseLibrary[i].getDifficultyLevel() <= 4) {
            exercises.push_back(exerciseLibrary[i]);
        } else if (user.getFitnessLevel() == "Advanced") {
            exercises.push_back(exerciseLibrary[i]);
        }
    }
}