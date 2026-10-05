void HealthTracker::trackProgress(User &user) {
    cout << "\nTracking Progress:" << endl;
    cout << "Current Weight: " << user.getWeight() << " kg" << endl;
    cout << "Goal Weight: " << goalWeight << " kg" << endl;
    cout << "Current Calorie Intake: " << user.getCalorieIntake() << " kcal" << endl;
    cout << "Goal Calorie Intake: " << goalCalories << " kcal" << endl;
}