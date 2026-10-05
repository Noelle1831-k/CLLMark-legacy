void ProgressTracker::logProgress() {
    ofstream file("progress.txt", ios::app);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }
    string progress;
    printf("Enter your progress for today: ");
    cin.ignore();
    getline(cin, progress);
    file << progress << endl;
    file.close();
    printf("Progress logged successfully!\n");
}