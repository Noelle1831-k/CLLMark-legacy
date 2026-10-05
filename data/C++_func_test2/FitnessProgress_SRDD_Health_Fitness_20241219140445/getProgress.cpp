void User::getProgress() const {
    cout << "Displaying progress for " << name << ":" << endl;
    for (int i = 0; i < workouts.size(); i++) {
        workouts[i].getWorkoutDetails();
    }
}