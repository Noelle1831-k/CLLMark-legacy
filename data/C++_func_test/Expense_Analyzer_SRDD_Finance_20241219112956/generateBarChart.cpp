void Visualization::generateBarChart(const map<string, double> &categoryTotals, const map<string, double> &budgets) const {
    printf("Bar Chart Representation (Spent vs Budget):\n");
    for (map<string, double>::const_iterator it = categoryTotals.begin(); it != categoryTotals.end(); ++it) {
        cout << it->first << " -> Spent: $" << it->second;
        if (budgets.find(it->first) != budgets.end()) {
            cout << ", Budget: $" << budgets.at(it->first);
        }
        printf("\n");
    }
}