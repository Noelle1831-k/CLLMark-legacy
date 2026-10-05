vector<string> filterActivities(const vector<string>& activities, const vector<string>& preferences) {
    vector<string> filtered;
    for (size_t i = 0; i < activities.size(); i++) {
        if (find(preferences.begin(), preferences.end(), activities[i]) != preferences.end()) {
            filtered.push_back(activities[i]);
        }
    }
    return filtered;
}