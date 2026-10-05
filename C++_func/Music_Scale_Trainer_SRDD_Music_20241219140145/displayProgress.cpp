void UserProgress::displayProgress() {
    cout << "\nUser Progress:\n";
    for (const auto& entry : progress) {
        cout << entry.first << ": " << entry.second << " correct answers" << endl;
    }
}