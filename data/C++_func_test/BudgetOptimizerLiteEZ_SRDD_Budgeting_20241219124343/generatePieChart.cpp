void Visualizer::generatePieChart(vector<pair<double, string>> incomes, vector<pair<double, string>> expenses) {
    cout << "\n[Pie Chart Placeholder]\n";
    cout << "Visualizing budget breakdown as a pie chart...\n";
    cout << "Income:\n";
    for (size_t i = 0; i < incomes.size(); ++i) {
        cout << "- $" << fixed << setprecision(2) << incomes[i].first << " from " << incomes[i].second << endl;
    }
    cout << "Expenses:\n";
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << "- $" << fixed << setprecision(2) << expenses[i].first << " for " << expenses[i].second << endl;
    }
}