void ProgressTracker::generateReport(const vector<Goal>& goals) const {
    cout << "\n--- Progress Report ---\n";
    for (size_t i = 0; i < goals.size(); ++i) {
        double percentage = (goals[i].getProgress() / goals[i].getTarget()) * 100;
        cout << "Goal: " << goals[i].getName()
             << " | Progress: " << percentage << "%\n";
    }
}