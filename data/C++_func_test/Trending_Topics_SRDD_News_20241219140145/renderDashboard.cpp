void DashboardRenderer::renderDashboard(const vector<pair<string, vector<string>>>& data) {
    cout << "\n--- Trending Topics Dashboard ---\n" << endl;
    for (auto& entry : data) {
        cout << "Topic: " << entry.first << endl;
        cout << "News Articles:" << endl;
        for (auto& article : entry.second) {
            cout << "- " << article << endl;
        }
        cout << endl;
    }
}