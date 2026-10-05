void User::trackProgress() {
    cout << "Tracking progress..." << endl;
    for (map<string, int>::iterator it = progress.begin(); it != progress.end(); ++it) {
        cout << "Exercise: " << it->first << ", Completion: " << it->second << "%" << endl;
    }
}