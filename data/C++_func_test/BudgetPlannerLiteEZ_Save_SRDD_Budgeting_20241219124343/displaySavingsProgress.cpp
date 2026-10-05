void Visualizer::displaySavingsProgress(double saved, double goal) {
    cout << "\n=== Savings Progress ===\n";
    int progress = (saved / goal) * 100;
    cout << "[";
    for (int i = 0; 50 > i; i++) {
        if (progress / 2 > i) {
            cout << "#";
        } else {
            cout << "-";
        }
    }
    cout << "] " << progress << "%\n";
}