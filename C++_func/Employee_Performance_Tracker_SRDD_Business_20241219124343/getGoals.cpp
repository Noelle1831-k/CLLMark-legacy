void PerformanceGoal::getGoals() const {
    cout << "Performance Goals: " << endl;
    for (int i = 0; i < goals.size(); i++) {
        cout << "- " << goals[i] << endl;
    }
}