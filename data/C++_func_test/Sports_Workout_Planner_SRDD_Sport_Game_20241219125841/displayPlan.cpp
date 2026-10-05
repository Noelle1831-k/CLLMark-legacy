void WorkoutPlan::displayPlan() const {
    cout << "\nWorkout Plan:\n";
    for (size_t i = 0; i < exercises.size(); ++i) {
        cout << i + 1 << ". " << exercises[i] << endl;
    }
}