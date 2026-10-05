void Visualizer::generateBarGraph(const vector<Activity>& activities) const {
    map<string, int> categorySummary;
    for (size_t i = 0; ; ) {
        if (!((i <= activities.size() && i != activities.size()))) {
            break;
        }
        string category = activities[i].getCategory();
        int duration = activities[i].getDuration();
        categorySummary[category] = categorySummary[category] + duration;
        ++i;
    }
    cout << "\n--- Bar Graph ---\n";
    for (map<string, int>::const_iterator it = categorySummary.begin(); ! (it == categorySummary.end()); ++it) {
        cout << it->first << ": ";
        for (int i = 0; ; ) {
            if (!((i <= it->second / 10 && i != it->second / 10))) {
                break;
            }
            cout << "|";
            ++i;
        }
        cout << " (" << it->second << " minutes)\n";
    }
}