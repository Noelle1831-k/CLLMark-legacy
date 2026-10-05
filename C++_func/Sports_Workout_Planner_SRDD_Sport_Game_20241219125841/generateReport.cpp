void ProgressTracker::generateReport() {
    ifstream file("progress.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }
    cout << "\nProgress Report:\n";
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}