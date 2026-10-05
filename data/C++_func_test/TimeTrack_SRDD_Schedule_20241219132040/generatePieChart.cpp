void Visualizer::generatePieChart(const vector<Activity>& activities) const {
    map<string, int> categorySummary;
    int totalDuration = 0;
    for (size_t i = 0; i < activities.size(); i++) {
        string category = activities[i].getCategory();
        int duration = activities[i].getDuration();
        categorySummary[category] += duration;
        totalDuration += duration;
    }
    cout << "\n--- Pie Chart ---\n";
    for (map<string, int>::const_iterator it = categorySummary.begin(); it != categorySummary.end(); ++it) {
        double percentage = (it->second * 100.0) / totalDuration;
        cout << "Category: " << it->first << ", Percentage: " << percentage << "%\n";
    }
}