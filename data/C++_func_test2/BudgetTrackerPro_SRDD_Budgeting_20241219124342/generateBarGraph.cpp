void Visualizer::generateBarGraph(const vector<pair<double, string>>& data) {
    cout << "Generating bar graph..." << endl;
    for (size_t i = 0; i < data.size(); i++) {
        cout << data[i].second << ": ";
        for (int j = 0; j < static_cast<int>(data[i].first); j++) {
            cout << "|";
        }
        cout << endl;
    }
}