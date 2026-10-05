void User::displayProgressHistory() const {
    cout << "Progress History: ";
    for (size_t i = 0; i < progress.size(); i++) {
        cout << progress[i];
        if (i < progress.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}