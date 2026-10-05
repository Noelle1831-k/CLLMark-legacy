void Visualizer::displayChart(const BudgetManager &manager) {
    cout << "\nBudget Visualization:\n";
    map<string, double> expenses = manager.getExpenses();
    for (const auto &pair : expenses) {
        cout << pair.first << ": ";
        for (int i = 0; i < (int)(pair.second / 10); ++i) {
            cout << "#";
        }
        cout << " ($" << pair.second << ")\n";
    }
}