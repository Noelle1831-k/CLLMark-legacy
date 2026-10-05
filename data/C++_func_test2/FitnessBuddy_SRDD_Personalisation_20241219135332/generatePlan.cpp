void WorkoutPlan::generatePlan(const User &user) {
    if (user.getFitnessGoal() == "lose weight") {
        planDetails = "30 minutes of cardio, 5 days a week.\n"
                      "Strength training, 2 days a week.\n";
    } else if (user.getFitnessGoal() == "gain muscle") {
        planDetails = "Strength training, 5 days a week.\n"
                      "High protein intake.\n";
    } else {
        planDetails = "30 minutes of moderate exercise daily.\n";
    }
}