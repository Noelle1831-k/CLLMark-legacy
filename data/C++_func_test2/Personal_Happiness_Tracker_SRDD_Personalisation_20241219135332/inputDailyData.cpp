void inputDailyData() {
        string mood, activity, event;
        cout << "Enter today's mood: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        getline(cin, mood);
        moodHistory.push_back(mood);
        cout << "Enter today's activities (comma-separated): ";
        getline(cin, activity);
        activityHistory.push_back(activity);
        cout << "Enter today's significant events: ";
        getline(cin, event);
        eventHistory.push_back(event);
    }