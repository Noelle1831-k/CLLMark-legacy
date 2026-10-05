void TimeTracker::displayAllActivities() const {
    cout << "\n--- All Logged Activities ---\n";
    for (size_t i = 0; i < activities.size(); i++) {
        activities[i].displayActivityDetails();
    }
}