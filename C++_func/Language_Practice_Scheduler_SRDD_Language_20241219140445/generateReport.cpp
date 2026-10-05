void ProgressTracker::generateReport() {
    cout << "Generating progress report..." << endl;
    for (const auto& progress : progressData) {
        cout << progress << endl;
    }
}