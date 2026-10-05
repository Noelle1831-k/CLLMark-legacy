void User::viewProgress() {
    cout << name << "'s Progress:" << endl;
    cout << "Total Activity Points: " << totalActivityPoints << endl;
    cout << "Activity Log:" << endl;
    for (size_t i = 0; i < activityLog.size(); i++) {
        cout << "- " << activityLog[i] << endl;
    }
}