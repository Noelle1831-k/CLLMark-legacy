void Habit::addProgress(int completedTime) {
    progress += completedTime;
    cout << "Progress for " << name << " is now " << progress << " minutes.\n";
}