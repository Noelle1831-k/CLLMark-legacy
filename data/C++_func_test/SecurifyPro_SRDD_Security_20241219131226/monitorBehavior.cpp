void UserBehaviorAnalyzer::monitorBehavior() {
    cout << "[UserBehaviorAnalyzer] Monitoring user behavior..." << endl;
    int i;
    for (i = 0; i < 7; i++) {
        cout << "[UserBehaviorAnalyzer] Checking activity " << i + 1 << "..." << endl;
        if (i % 4 == 0) {
            cout << "[UserBehaviorAnalyzer] Unusual behavior detected in activity " << i + 1 << "!" << endl;
        }
    }
    cout << "[UserBehaviorAnalyzer] User behavior monitoring completed." << endl;
}