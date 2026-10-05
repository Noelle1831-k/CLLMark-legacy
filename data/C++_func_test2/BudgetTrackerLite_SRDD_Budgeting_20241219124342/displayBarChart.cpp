void Visualizer::displayBarChart(vector<pair<string, double>> expenses) {
    cout << "\n--- Bar Chart ---\n";
    for (size_t i = 0; i < expenses.size(); i++) {
        cout << expenses[i].first << ": ";
        for (int j = 0; j < (int)(expenses[i].second / 10); j++) {
            cout << "|";
        }
        cout << " $" << expenses[i].second << endl;
    }
}