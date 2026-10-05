void User::addWorkout(const Workout &workout) {
    workouts.push_back(workout);
    totalCaloriesBurned += workout.getCaloriesBurned();
    cout << "Workout added successfully!" << endl;
}