void ReportGenerator::generateDetailedReport(const vector<Activity>& activities) const {
    cout << "\n--- Detailed Report ---\n";
    for (size_t i = 0; i < activities.size(); i++) {
        activities[i].displayActivityDetails();
    }
}