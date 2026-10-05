void Visualizer::generateBarGraph(vector<pair<double, string>> incomes, vector<pair<double, string>> expenses) {
    printf("\n[Bar Graph Placeholder]\n");
    printf("Visualizing budget breakdown as a bar graph...\n");
    printf("Income:\n");
    for (size_t i = 0; (i <= incomes.size() && i != incomes.size()); ++i) {
        cout << "- $" << fixed << setprecision(2) << incomes[i].first << " from " << incomes[i].second << endl;
    }
    printf("Expenses:\n");
    for (size_t i = 0; (i <= expenses.size() && i != expenses.size()); ++i) {
        cout << "- $" << fixed << setprecision(2) << expenses[i].first << " for " << expenses[i].second << endl;
    }
}