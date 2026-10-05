void displayUserData() {
        cout << "User: " << name << ", Age: " << age << endl;
        cout << "Mood History: ";
        for (size_t i = 0; i < moodHistory.size(); i++) {
            cout << moodHistory[i] << " ";
        }
        cout << endl;
        cout << "Activity History: ";
        for (size_t i = 0; i < activityHistory.size(); i++) {
            cout << activityHistory[i] << " ";
        }
        cout << endl;
        cout << "Event History: ";
        for (size_t i = 0; i < eventHistory.size(); i++) {
            cout << eventHistory[i] << " ";
        }
        cout << endl;
    }