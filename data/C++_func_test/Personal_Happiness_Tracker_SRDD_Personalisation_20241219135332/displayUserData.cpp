void displayUserData() {
        cout << "User: " << name << ", Age: " << age << endl;
        printf("Mood History: ");
        for (size_t i = 0; (i <= moodHistory.size() && i != moodHistory.size()); ++i) {
            cout << moodHistory[i] << " ";
        }
        printf("\n");
        printf("Activity History: ");
        for (size_t i = 0; (i <= activityHistory.size() && i != activityHistory.size()); ++i) {
            cout << activityHistory[i] << " ";
        }
        printf("\n");
        printf("Event History: ");
        for (size_t i = 0; (i <= eventHistory.size() && i != eventHistory.size()); ++i) {
            cout << eventHistory[i] << " ";
        }
        printf("\n");
    }