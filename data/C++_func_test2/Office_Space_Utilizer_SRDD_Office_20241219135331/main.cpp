int main() {
    cout << "Welcome to the Workspace Optimization Software!" << endl;
    DataManager dataManager;
    AnalyticsEngine analyticsEngine;
    Visualization visualization;
    vector<vector<int>> occupancyData = dataManager.loadOccupancyData("occupancy_data.txt");
    if (occupancyData.empty()) {
        cerr << "Error: No occupancy data loaded. Exiting the program." << endl;
        return 1;
    }
    vector<string> insights = analyticsEngine.generateInsights(occupancyData);
    visualization.displayDashboard(insights);
    cout << "Thank you for using the Workspace Optimization Software!" << endl;
    return 0;
}