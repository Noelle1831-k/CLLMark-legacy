int main() {
    User user;
    WorkoutLibrary workoutLibrary;
    WorkoutPlan workoutPlan;
    WorkoutTracker workoutTracker;
    cout << "Enter your fitness goals (e.g., Strength, Cardio): ";
    string goal;
    getline(cin, goal);
    user.setFitnessGoal(goal);
    cout << "Enter your current fitness level (Beginner, Intermediate, Advanced): ";
    string level;
    getline(cin, level);
    user.setFitnessLevel(level);
    cout << "Enter your available equipment (e.g., Dumbbells, Resistance bands, None): ";
    string equipment;
    getline(cin, equipment);
    user.setEquipment(equipment);
    cout << "Enter your preferred workout duration (in minutes): ";
    int duration;
    cin >> duration;
    user.setWorkoutDuration(duration);
    workoutPlan.generatePlan(user, workoutLibrary);
    workoutTracker.startTracking(user, workoutPlan);
    workoutPlan.displayPlan();
    workoutTracker.displayProgress();
    return 0;
}