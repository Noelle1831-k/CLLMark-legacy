void Visualizer::displaySavingsProgress(double saved, double goal) {
    cout << "\n=== Savings Progress ===\n";
    int progress = (saved / goal) * 100;
    cout << "[";
    for (int i = 0; i < 50; i++) {
        if (i < progress / 2) {
            cout << "#";
        } else {
            cout << "-";
        }
    }
    cout << "] " << progress << "%\n";
}