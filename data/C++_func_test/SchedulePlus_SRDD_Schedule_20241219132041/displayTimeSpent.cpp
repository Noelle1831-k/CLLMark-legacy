void TimeTracker::displayTimeSpent() const {
    cout << "Time spent on Task ID " << taskId << ": " << calculateTimeSpent() << " seconds." << endl;
}