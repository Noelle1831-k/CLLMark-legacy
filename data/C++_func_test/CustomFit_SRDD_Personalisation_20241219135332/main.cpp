int main(void) {
    UserProfile user;
    WorkoutPlan plan;
    ExerciseLibrary library;
    ProgressTracker tracker;
    cout << "Welcome to CustomFit - Your Personalized Workout Planner!" << endl;
    user.getUserData();
    user.displayProfile();
    plan.generatePlan(user);
    plan.displayPlan();
    library.getExerciseDetails();
    library.displayExercise();
    tracker.updateProgress();
    tracker.displayProgress();
    cout << "Thank you for using CustomFit. Stay fit and healthy!" << endl;
    return 0;
}