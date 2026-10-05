void Visualizer::generatePieChart(const vector<pair<double, string>>& data) {
    cout << "Generating pie chart..." << endl;
    for (size_t i = 0; i < data.size(); i++) {
        cout << data[i].second << ": " << data[i].first << endl;
    }
}