void ProgressTracker::trackProgress(const vector<string>& goals) {
    cout << "Tracking progress for your goals..." << endl;
    for (size_t i = 0; i < goals.size(); ++i) {
        progressData.push_back("Progress on " + goals[i] + ": 50% completed");
    }
}