void ReportGenerator::generateCategorySummary(const vector<Activity>& activities) const {
    map<string, int> categorySummary;
    for (size_t i = 0; i < activities.size(); i++) {
        string category = activities[i].getCategory();
        int duration = activities[i].getDuration();
        categorySummary[category] += duration;
    }
    cout << "\n--- Category Summary ---\n";
    for (map<string, int>::const_iterator it = categorySummary.begin(); it != categorySummary.end(); ++it) {
        cout << "Category: " << it->first << ", Total Time: " << it->second << " minutes\n";
    }
}