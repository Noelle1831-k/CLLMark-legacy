void DashboardRenderer::renderFilteredNews(const vector<string>& filteredNews) {
    cout << "\n--- Filtered News Articles ---\n" << endl;
    for (auto& article : filteredNews) {
        cout << "- " << article << endl;
    }
    cout << endl;
}