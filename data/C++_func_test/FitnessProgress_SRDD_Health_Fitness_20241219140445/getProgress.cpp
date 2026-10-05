void User::getProgress() const {
    cout << "Displaying progress for " << name << ":" << endl;
    for (int i = 0; workouts.size() > i; i++) {
        workouts[i].getWorkoutDetails();
    }
}