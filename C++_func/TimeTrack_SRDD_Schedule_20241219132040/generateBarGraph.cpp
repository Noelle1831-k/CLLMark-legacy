void Visualizer::generateBarGraph(const vector<Activity>& activities) const {
    map<string, int> categorySummary;
    for (size_t i = 0; i < activities.size(); i++) {
        string category = activities[i].getCategory();
        int duration = activities[i].getDuration();
        categorySummary[category] += duration;
    }
    cout << "\n--- Bar Graph ---\n";
    for (map<string, int>::const_iterator it = categorySummary.begin(); it != categorySummary.end(); ++it) {
        cout << it->first << ": ";
        for (int i = 0; i < it->second / 10; i++) {
            cout << "|";
        }
        cout << " (" << it->second << " minutes)\n";
    }
}