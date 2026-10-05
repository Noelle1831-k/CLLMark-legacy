void FitnessBuddyApp::run() {
    cout << "Welcome to FitnessBuddy!" << endl;
    User user;
    user.inputDetails();
    DataAnalyzer analyzer;
    analyzer.analyze(user);
    WorkoutPlan workoutPlan;
    NutritionPlan nutritionPlan;
    workoutPlan.generatePlan(user);
    nutritionPlan.generatePlan(user);
    cout << "\nYour Personalized Workout Plan:" << endl;
    workoutPlan.displayPlan();
    cout << "\nYour Personalized Nutrition Plan:" << endl;
    nutritionPlan.displayPlan();
}