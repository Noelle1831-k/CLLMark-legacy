void Visualizer::generateBarChart(const vector<pair<string, int>> &data) {
    cout << "\n========== Bar Chart ==========" << endl;
    for (size_t i = 0; i < data.size(); i++) {
        cout << data[i].first << " ";
        for (int j = 0; j < data[i].second; j++) {
            cout << "|";
        }
        cout << endl;
    }
    cout << "===============================" << endl;
}