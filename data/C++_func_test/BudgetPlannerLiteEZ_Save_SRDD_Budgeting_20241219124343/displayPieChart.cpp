void Visualizer::displayPieChart(map<string, double> expenses) {
    cout << "\n=== Expense Pie Chart ===\n";
    double total = 0;
    for (auto &expense : expenses) {
        total += expense.second;
    }
    for (auto &expense : expenses) {
        double percentage = (expense.second / total) * 100;
        cout << expense.first << ": " << fixed << setprecision(2) << percentage << "%\n";
    }
}