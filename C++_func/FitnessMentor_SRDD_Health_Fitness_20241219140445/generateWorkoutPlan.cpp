void FitnessMentorApp::generateWorkoutPlan(const User& user) {
    WorkoutPlan plan(user, exerciseLibrary);
    cout << "Generated Workout Plan for " << user.getName() << ":" << endl;
    plan.displayPlan();
}